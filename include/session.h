/**
 * @file session.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-31
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <memory>

#include <boost/asio.hpp>

#include <message.h>
#include <util.h>

namespace DR {

    typedef boost::asio::ip::tcp::socket dr_sock_t;
    typedef boost::asio::streambuf dr_buf_t;
    typedef boost::system::error_code dr_err_t;
    typedef boost::asio::io_context dr_ctx_t;

#define dr_pl_err boost::asio::placeholders::error
#define dr_pl_bytes boost::asio::placeholders::bytes_transferred
#define dr_sep '\n'

    /**
     * @brief Less ugly tostring function for buffer
     *
     * @param buf
     * @param size
     * @return string
     */
    static std::string make_string(dr_buf_t* buf, size_t size) {
        std::string s(boost::asio::buffer_cast<const char*>(buf->data()), size);
        buf->consume(size);
        return s;
    }

    class Session {
        std::unique_ptr<dr_sock_t> sock;
        boost::asio::io_context::strand r_strand, w_strand;
        dr_buf_t rbuf;
        // Internal state
        dr_err_t err;

        void parseMessage(const dr_err_t& err, std::size_t size);
        // Let subclass override
    protected:
        virtual void handleWriteMessage(dr_buf_t* wbuf, const dr_err_t& err, std::size_t size);
        virtual void handleReadMessage(Message&& m) = 0;
    public:
        Session(std::unique_ptr<dr_sock_t> sock, dr_ctx_t& ctx);

        void asyncReadCall();

        void writeMessage(const Message& m);
        void writeMessage(Message&& m);

        const dr_err_t& getErr() const noexcept { return err; }
    };
}