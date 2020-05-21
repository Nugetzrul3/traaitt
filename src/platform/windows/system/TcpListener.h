// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2018-2020, The TurtleCoin Developers
// Copyright (c) 2020, TRRXITTE inc. development Team
//
// Please see the included LICENSE file for more information.

#pragma once

#include <cstdint>
#include <string>

namespace System
{
    class Dispatcher;

    class Ipv4Address;

    class TcpConnection;

    class TcpListener
    {
      public:
        TcpListener();

        TcpListener(Dispatcher &dispatcher, const Ipv4Address &address, uint16_t port);

        TcpListener(const TcpListener &) = delete;

        TcpListener(TcpListener &&other);

        ~TcpListener();

        TcpListener &operator=(const TcpListener &) = delete;

        TcpListener &operator=(TcpListener &&other);

        TcpConnection accept();

      private:
        Dispatcher *dispatcher;

        size_t listener;

        void *context;
    };

} // namespace System