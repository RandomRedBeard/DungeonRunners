/**
 * @file test_socket.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <boost/asio.hpp>
#include <boost/json.hpp>
#include <point.h>
#include <iostream>
#include <string>
#include <assert.h>

void test_socket() {
    boost::asio::io_context ctx;
    auto addr = boost::asio::ip::make_address("127.0.0.1");
    auto ep = boost::asio::ip::tcp::endpoint(addr, 8080);

    boost::asio::ip::tcp::acceptor acceptor(ctx);
    acceptor.open(ep.protocol());
    acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
    acceptor.bind(ep);
    acceptor.listen();

    auto cl = boost::asio::ip::tcp::socket(ctx, ep.protocol());
    cl.connect(ep);

    auto s1 = acceptor.accept();

    DR::Point pt(1, 1);
    auto tree = pt.Serializable::serialize();
    boost::asio::streambuf wbuf;
    std::ostream os(&wbuf);
    boost::property_tree::write_json(os, tree);
    size_t nbytes = boost::asio::write(cl, wbuf);

    puts("Wrote data");

    boost::asio::streambuf rbuf;
    std::istream is(&rbuf);
    boost::asio::read(s1, rbuf, boost::asio::transfer_exactly(nbytes));

    puts("Read data");

    DR::Serial se;
    boost::property_tree::read_json(is, se);

    DR::Point pt1;
    pt1.deserialize(se);
    pt1.print();

    assert(pt1.x == 1);

    cl.close();
    s1.close();

    acceptor.close();
}

void handle_accept(const boost::system::error_code& error, boost::asio::ip::tcp::socket&& s) {
    boost::asio::streambuf buf;
    boost::asio::read_until(s, buf, '\n');
    std::cout << (char*)buf.data().data();
    s.write_some(boost::asio::buffer("test"));
    s.close();
}

void test_server() {
    boost::asio::io_context ctx;
    auto addr = boost::asio::ip::make_address("0.0.0.0");
    auto ep = boost::asio::ip::tcp::endpoint(addr, 8080);

    boost::asio::ip::tcp::acceptor acceptor(ctx);
    acceptor.open(ep.protocol());
    acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
    acceptor.bind(ep);
    acceptor.listen();

    while (1) {
        acceptor.async_accept(handle_accept);
        ctx.run();
        ctx.restart();
    }
}

int main() {
    test_socket();
    test_server();
}