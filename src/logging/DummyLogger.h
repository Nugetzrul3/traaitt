// Copyright (c) 2018-2020, The TurtleCoin Developers
// Copyright (c) 2020, TRRXITTE inc. development Team
//
// Please see the included LICENSE file for more information.

#pragma once

#include <logging/ILogger.h>

namespace Logging
{
    class DummyLogger : public ILogger
    {
      public:
        virtual ~DummyLogger() {};

        virtual void
            operator()(const std::string &category, Level level, boost::posix_time::ptime time, const std::string &body)
                override
        {
            // do nothing
        }
    };

} // namespace Logging
