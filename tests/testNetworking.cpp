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

#include <boost/asio/thread_pool.hpp>
#include <boost/asio.hpp>
#include <boost/json.hpp>
#include <point.h>
#include <iostream>
#include <string>
#include <assert.h>
#include <instance.h>
#include <message.h>
#include <player.h>
#include <cstring>

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
    vector<shared_ptr<Player>> players;

    Serial serialize(Serial& o) const noexcept {
        o.put_child("instance", instance.newSerialize());

        Serial playersJson;
        for (auto& p : players) {
            playersJson.push_back({ "", p->newSerialize() });
        }

        o.put_child("players", playersJson);

        return o;
    }

    void deserialize(const Serial& o) {
        instance.deserialize(o.get_child("instance"));

        for (auto& o : o.get_child("players")) {
            shared_ptr<Player> player = make_shared<Player>();
            player->deserialize(o.second);
            players.push_back(player);
        }
    }
};

/**
 * @brief Less ugly tostring function for buffer
 *
 * @param buf
 * @param size
 * @return string
 */
string make_string(dr_buf_t* buf, size_t size) {
    string s(boost::asio::buffer_cast<const char*>(buf->data()), size);
    buf->consume(size);
    return s;
}

class Session {
    unique_ptr<dr_socket_t> socket_;
    boost::asio::io_context::strand r_strand, o_strand;
    dr_buf_t rbuf;
    DM* dm;
    Player* player;
public:
    Session(DM* dm, Player* player, dr_socket_t* socket_, boost::asio::io_context* ctx) : dm(dm), player(player), socket_(socket_), r_strand(*ctx), o_strand(*ctx) {}

    virtual ~Session() {
        socket_->close();
    }

    void asyncReadCall() {
        cout << "read call" << endl;
        boost::asio::async_read_until(*socket_, rbuf, MESSAGE_SEP, r_strand.wrap(boost::bind(&Session::parseMessage, this, pl_err, pl_bytes)));
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

    void writeMessage(Message& m) {
        Serial ser = m.newSerialize();
        // Maybe reuse wbuf?
        dr_buf_t* wbuf = new dr_buf_t();;
        std::ostream os(wbuf);
        boost::property_tree::write_json(os, ser, false);

        boost::asio::async_write(*socket_, *wbuf, o_strand.wrap(boost::bind(&Session::handleWriteMessage, this, wbuf, pl_err, pl_bytes)));
    }

    void requestPlayerJoinInstance(shared_ptr<Player> p) {
        Message rjoin(PL_INST_JN_REQ, p->newSerialize());
        writeMessage(rjoin);
    }

    void handleDM(Message& m) {
        cout << "Handling incoming DM" << endl;
        dm->deserialize(m.getBody());
        Message nm("RequestPlayer", player->newSerialize());
        writeMessage(nm);
    }

    void handleRequestPlayer(Message& m) {
        cout << "Handling request player" << endl;
        m.print();
        shared_ptr<Player> p = make_shared<Player>();
        p->deserialize(m.getBody());
        p->setId(OID::generate());
        Point pt = dm->instance.randPoint();
        p->setPoint(pt);
        dm->instance.addPlayer(p, pt);
        dm->players.push_back(p);

        Message nm("AckRequestPlayer", p->newSerialize());
        writeMessage(nm);
    }

    void handleAckRequestPlayer(Message& m) {
        cout << "Reading player" << endl;
        player->deserialize(m.getBody());
        player->print();

        cout << "Done handshake" << endl;
    }

    void requestMove(Point dest) {
        Serial moveRequest = dest.newSerialize();
        player->getId().serialize(moveRequest);

        cout << "Writing move request message" << endl;

        Message mr("MoveRequest", move(moveRequest));
        writeMessage(mr);
    }

    void handleRequestMove(Message& m) {
        const Serial& s = m.getBody();

        cout << "Move request handle" << endl;
        m.print();

        OID id;
        id.deserialize(s);
        Point pt;
        pt.deserialize(s);

        // const auto players = dm->instance.getPlayers();
        const auto& p = dm->instance.getPlayers().find(id);
        if (p != dm->instance.getPlayers().end()) {
            if (dm->instance.move(p->second, p->second->getPoint(), pt)) {
                p->second->setPoint(pt);
                Message ack("AckMoveRequest", p->second->newSerialize());
                writeMessage(ack);
            }
            else {
                Message ack("RejMoveRequest", p->second->newSerialize());
                writeMessage(ack);
            }
        }

        // if (dm->instance.move(id, pt)) {
        //     Message ack("AckMoveRequest", s);
        //     writeMessage(ack);
        // } else {
        //     Message rej("RejMoveRequest", s);
        //     writeMessage(ack);
        // }
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

        cout << "Unhandled message" << endl;
        m.print();
    }

    void handleWriteMessage(dr_buf_t* wbuf, const dr_err& error, size_t size) {
        cout << "Wrote " << size << endl;
        delete wbuf;
    }
};

class Client {
    unique_ptr<Session> session;
    DM dm;
    Player* player;
public:
    Client(Player* player, boost::asio::io_context* ctx, boost::asio::ip::tcp::endpoint ep) : player(player) {
        dr_socket_t* socket_ = new dr_socket_t(*ctx);
        session = make_unique<Session>(&dm, player, socket_, ctx);
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

    void handleAccept(Session* session, const boost::system::error_code& error) {
        // Send instance
        Message m("DM", dm.newSerialize());
        session->writeMessage(m);
        // After writing DM, listen
        session->asyncReadCall();

        asyncAccept();
    }

    void asyncAccept() {
        dr_socket_t* socket_ = new dr_socket_t(*ctx);
        Session* session = new Session(&dm, nullptr, socket_, ctx);
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
    Instance inst(OID::generate(), Map(80, 25, 3, 3));
    boost::asio::io_context ctx;
    auto addr = boost::asio::ip::make_address("127.0.0.1");
    auto ep = boost::asio::ip::tcp::endpoint(addr, 8080);

    Server server(&ctx, ep, move(inst));
    server.asyncAccept();
    Player p;
    p.setName("Thomas");
    Client cl1(&p, &ctx, ep);

    thread ithread(&test_input_thread, &cl1);
    // Client cl2(&ctx, ep);

    thread t1(&io_thread, &ctx);
    thread t2(&io_thread, &ctx);

    ctx.run();

    cl1.close();
    // cl2.close();
    server.close();
    t1.join();
    t2.join();

    return 0;
}