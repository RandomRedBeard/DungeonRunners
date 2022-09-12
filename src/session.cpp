/**
 * @file session.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-31
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "session.h"

DR::Session::Session(std::unique_ptr<dr_sock_t> sock, dr_ctx_t& ctx) : sock(move(sock)), r_strand(ctx), w_strand(ctx) {}

void DR::Session::parseMessage(const dr_err_t& err, std::size_t size) {
    std::string sbuf = make_string(&rbuf, size);
    std::istringstream is(sbuf);
    Serial se;
    boost::property_tree::read_json(is, se);

    handleReadMessage(Message(se));

    asyncReadCall();
}

void DR::Session::handleWriteMessage(dr_buf_t* wbuf, const dr_err_t& err, std::size_t size) {
    // Clear write buffer
    delete wbuf;
}

void DR::Session::asyncReadCall() {
    boost::asio::async_read_until(*sock, rbuf, dr_sep, r_strand.wrap(boost::bind(&Session::parseMessage, this, dr_pl_err, dr_pl_bytes)));
}

void DR::Session::writeMessage(const Message& m) {
    Serial ser = m.newSerialize();
    // Maybe reuse wbuf?
    dr_buf_t* wbuf = new dr_buf_t();;
    std::ostream os(wbuf);
    boost::property_tree::write_json(os, ser, false);

    boost::asio::async_write(*sock, *wbuf, w_strand.wrap(boost::bind(&Session::handleWriteMessage, this, wbuf, dr_pl_err, dr_pl_bytes)));
}

void DR::Session::writeMessage(Message&& m) {
    writeMessage(m);
}