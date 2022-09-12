/**
 * @file testNetworking.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-22
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <boost/asio.hpp>
#include <boost/function.hpp>

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <shared_mutex>

#include <assert.h>

#include <message.h>
#include <arg.h>
#include <mapPathfinder.h>
#include <instance.h>
#include <map.h>
#include <pathfinder.h>
#include <cGraphics.h>
#include <player.h>
#include <monster.h>
#include <session.h>

#define PL_INST_JN_REQ "PlayerJoinInstance"

using namespace std;
using namespace DR;

typedef boost::asio::ip::tcp::socket dr_socket_t;
typedef boost::asio::streambuf dr_buf_t;
#define pl_err boost::asio::placeholders::error
#define pl_bytes boost::asio::placeholders::bytes_transferred
typedef boost::system::error_code dr_err;

#define MESSAGE_SEP '\n'

struct DM : public Serializable {
    Instance instance;
    boost::uuids::random_generator idGen;
    map<boost::uuids::uuid, shared_ptr<Player>> players;

    Serial serialize(Serial& o) const noexcept {
        o.put_child("instance", instance.newSerialize());

        Serial playersJson;
        for (auto& p : players) {
            playersJson.push_back({ "", p.second->newSerialize() });
        }

        o.put_child("players", playersJson);

        return o;
    }

    void deserialize(const Serial& o) {
        instance.deserialize(o.get_child("instance"));

        for (auto& o : o.get_child("players")) {
            shared_ptr<Player> player = make_shared<Player>();
            player->deserialize(o.second);
            players.insert_or_assign(player->getId(), player);
        }
    }
};

class Broadcaster {
    vector<shared_ptr<class CSession>> sessions;
    shared_mutex s_mutex;
public:
    void addSession(shared_ptr<CSession> session);
    shared_ptr<CSession> removeSession(unsigned int i);
    void broadcast(const Message& m);
};

class CSession {
    unique_ptr<dr_socket_t> socket_;
    boost::asio::io_context::strand r_strand, o_strand;
    dr_buf_t rbuf;
    // Maybe uninitialized
    DM* dm;
    // Maybe null
    Player* player;

    // Broadcast
    Broadcaster* broadcaster;
public:
    CSession(DM* dm, Player* player, Broadcaster* broadcaster, dr_socket_t* socket_, boost::asio::io_context* ctx) : dm(dm), player(player), broadcaster(broadcaster), socket_(socket_), r_strand(*ctx), o_strand(*ctx) {}

    virtual ~CSession() {
        socket_->close();
    }

    void asyncReadCall() {
        cout << "read call" << endl;
        boost::asio::async_read_until(*socket_, rbuf, MESSAGE_SEP, r_strand.wrap(boost::bind(&CSession::parseMessage, this, pl_err, pl_bytes)));
    }

    /**
     * @brief Reads rbuf for some Message
     *
     * @param error
     * @param size
     */
    void parseMessage(const dr_err& error, size_t size) {
        string sbuf = make_string(&rbuf, size);
        istringstream is(sbuf);
        Serial se;
        boost::property_tree::read_json(is, se);

        Message m(se);
        handleMessage(m);

        asyncReadCall();
    }

    void writeMessage(const Message& m) {
        Serial ser = m.newSerialize();
        // Maybe reuse wbuf?
        dr_buf_t* wbuf = new dr_buf_t();;
        std::ostream os(wbuf);
        boost::property_tree::write_json(os, ser, false);

        boost::asio::async_write(*socket_, *wbuf, o_strand.wrap(boost::bind(&CSession::handleWriteMessage, this, wbuf, pl_err, pl_bytes)));
    }

    void requestPlayerJoinInstance(shared_ptr<Player> p) {
        Message rjoin(PL_INST_JN_REQ, p->newSerialize());
        writeMessage(rjoin);
    }

    void handleDM(Message& m) {
        cout << "Handling incoming DM" << endl;
        dm->deserialize(m.getBody());
        if (dm->players.size() > 0) {
            cout << "Got players " << endl;
            for (auto& p : dm->players) {
                p.second->print();
            }
        }
        Message nm("RequestPlayer", player->newSerialize());
        writeMessage(nm);
    }

    void handleRequestPlayer(Message& m) {
        cout << "Handling request player" << endl;
        m.print();
        shared_ptr<Player> p = make_shared<Player>();
        p->deserialize(m.getBody());
        p->setId(dm->idGen());
        Point pt = dm->instance.randPoint();
        p->setPoint(pt);
        dm->instance.addPlayer(p, pt);
        dm->players.insert_or_assign(p->getId(), p);

        cout << "Server player count " << dm->players.size() << endl;

        Message nm("AckRequestPlayer", p->newSerialize());
        writeMessage(nm);

        Message np("NewPlayer", p->newSerialize());
        broadcaster->broadcast(np);
    }

    void handleAckRequestPlayer(Message& m) {
        cout << "Reading player" << endl;
        player->deserialize(m.getBody());
        player->print();

        cout << "Done handshake" << endl;
    }

    void requestMove(Point dest) {
        Serial moveRequest = dest.newSerialize();
        moveRequest.put("id", player->getId());

        cout << "Writing move request message" << endl;

        Message mr("MoveRequest", move(moveRequest));
        writeMessage(mr);
    }

    void handleRequestMove(Message& m) {
        const Serial& s = m.getBody();

        cout << "Move request handle" << endl;
        m.print();

        boost::uuids::uuid id;
        id = s.get<boost::uuids::uuid>("id");
        Point pt;
        pt.deserialize(s);

        // const auto players = dm->instance.getPlayers();
        const auto& p = dm->instance.getPlayers().find(id);
        if (p != dm->instance.getPlayers().end()) {
            if (dm->instance.move(p->second, p->second->getPoint(), pt)) {
                p->second->setPoint(pt);
                Message ack("AckMoveRequest", p->second->newSerialize());
                writeMessage(ack);

                Message mm("PlayerMove", p->second->newSerialize());
                broadcaster->broadcast(mm);
            }
            else {
                Message ack("RejMoveRequest", p->second->newSerialize());
                writeMessage(ack);
            }
        }
    }

    void handleNewPlayer(Message& m) {
        Player p;
        p.deserialize(m.getBody());

        cout << "New Player " << p.getId() << endl;

        if (p.getId() == player->getId()) {
            cout << "New player is me" << endl;
            cout << dm->players.size() << endl;
            return;
        }
        dm->players.insert_or_assign(p.getId(), make_shared<Player>(p));

        cout << "Added Player " << endl;
        p.print();
    }

    void handlePlayerMove(Message& m) {
        Player p;
        p.deserialize(m.getBody());
        if (p.getId() == player->getId()) {
            cout << "I moved" << endl;
        }
        else {
            auto rp = dm->players[p.getId()];
            rp->setPoint(p.getPoint());
            cout << "Other moved" << endl;
            rp->print();
        }
    }

    void handleMessage(Message& m) {
        if (m.getType() == "DM") {
            return handleDM(m);
        }
        else if (m.getType() == "RequestPlayer") {
            return handleRequestPlayer(m);
        }
        else if (m.getType() == "AckRequestPlayer") {
            return handleAckRequestPlayer(m);
        }
        else if (m.getType() == "MoveRequest") {
            return handleRequestMove(m);
        }
        else if (m.getType() == "NewPlayer") {
            return handleNewPlayer(m);
        }
        else if (m.getType() == "PlayerMove") {
            return handlePlayerMove(m);
        }

        cout << "Unhandled message" << endl;
        m.print();
    }

    void handleWriteMessage(dr_buf_t* wbuf, const dr_err& error, size_t size) {
        cout << "Wrote " << size << endl;
        if (size == 0) {
            cout << boost::asio::buffer_cast<const char*>(wbuf->data()) << endl;
        }
        delete wbuf;
    }
};

void Broadcaster::addSession(shared_ptr<CSession> session) {
    unique_lock ulock(s_mutex);
    sessions.push_back(session);
}

shared_ptr<CSession> Broadcaster::removeSession(unsigned int i) {
    unique_lock ulock(s_mutex);
    auto it = sessions.erase(sessions.begin() + i);
    return *it;
}

void Broadcaster::broadcast(const Message& m) {
    shared_lock rlock(s_mutex);
    for (auto& s : sessions) {
        s->writeMessage(m);
    }
}

class Client {
    unique_ptr<CSession> session;
    DM dm;
    Player* player;
public:
    Client(Player* player, boost::asio::io_context* ctx, boost::asio::ip::tcp::endpoint ep) : player(player) {
        dr_socket_t* socket_ = new dr_socket_t(*ctx);
        session = make_unique<CSession>(&dm, player, nullptr, socket_, ctx);
        socket_->async_connect(ep, boost::bind(&Client::handleConnect, this, pl_err));
    }

    void handleConnect(const boost::system::error_code& error) {
        session->asyncReadCall();
    }

    void move(Point pt) {
        session->requestMove(pt);
    }

    const DM& getDM() const noexcept { return dm; }

    const Player* getPlayer() const noexcept { return player; }

    void close() {
    }
};

class Server {
    boost::asio::io_context* ctx;
    boost::asio::ip::tcp::acceptor acceptor;
    DM dm;
    Broadcaster broadcaster;
public:
    Server(boost::asio::io_context* ctx, boost::asio::ip::tcp::endpoint ep, Instance&& instance) : ctx(ctx), acceptor(*ctx) {
        dm.instance = move(instance);

        acceptor.open(ep.protocol());
        acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
        acceptor.bind(ep);
        acceptor.listen();
    }

    void close() {
        acceptor.close();
    }

    void handleAccept(shared_ptr<CSession> session, const boost::system::error_code& error) {
        // Send instance
        Message m("DM", dm.newSerialize());
        session->writeMessage(m);
        // After writing DM, listen
        session->asyncReadCall();

        asyncAccept();
    }

    void asyncAccept() {
        dr_socket_t* socket_ = new dr_socket_t(*ctx);
        shared_ptr<CSession> session = make_shared<CSession>(&dm, nullptr, &broadcaster, socket_, ctx);
        broadcaster.addSession(session);
        acceptor.async_accept(*socket_, boost::bind(&Server::handleAccept, this, session, pl_err));
    }

};

void io_thread(boost::asio::io_context* ctx) {
    ctx->run();
}

void test_input_thread(Client* client) {
    this_thread::sleep_for(chrono::seconds(2));

    cout << "Moving" << endl;

    cout << client->getDM().instance.getMap()->getPoint(client->getPlayer()->getPoint()) << endl;

    Point pt = client->getPlayer()->getPoint().move(Direction::LEFT);
    client->move(pt);
}

int main() {
    boost::uuids::random_generator idGen;
    Instance inst(idGen(), Map(80, 25, 3, 3));
    boost::asio::io_context ctx;
    auto addr = boost::asio::ip::make_address("127.0.0.1");
    auto ep = boost::asio::ip::tcp::endpoint(addr, 8080);

    Server server(&ctx, ep, move(inst));
    server.asyncAccept();
    Player p1, p2;
    p1.setName("Thomas");
    p2.setName("Also Thomas");
    Client cl1(&p1, &ctx, ep);

    thread ithread(&test_input_thread, &cl1);
    Client cl2(&p2, &ctx, ep);

    thread t1(&io_thread, &ctx);
    thread t2(&io_thread, &ctx);

    ctx.run();

    cl1.close();
    cl2.close();
    server.close();
    t1.join();
    t2.join();

    return 0;
}