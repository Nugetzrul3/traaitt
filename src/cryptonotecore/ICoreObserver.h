// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2018-2020, The TurtleCoin Developers
// Copyright (c) 2020, TRRXITTE inc. development Team
//
// Please see the included LICENSE file for more information.

#pragma once

namespace CryptoNote
{
    class ICoreObserver
    {
      public:
        virtual ~ICoreObserver() {};

        virtual void blockchainUpdated() {};

        virtual void poolUpdated() {};
    };

} // namespace CryptoNote
