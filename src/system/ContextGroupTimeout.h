// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2018-2019, The TurtleCoin Developers
// Copyright (c) 2019-2020, The Cirquity Developers
//
// Please see the included LICENSE file for more information.

#pragma once

#include <chrono>
#include <system/ContextGroup.h>
#include <system/Timer.h>

namespace System
{
    class ContextGroupTimeout
    {
      public:
        ContextGroupTimeout(Dispatcher &, ContextGroup &, std::chrono::nanoseconds);

      private:
        Timer timeoutTimer;

        ContextGroup workingContextGroup;
    };

} // namespace System
