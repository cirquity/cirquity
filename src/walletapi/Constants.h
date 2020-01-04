// Copyright (c) 2018-2019, The TurtleCoin Developers
// Copyright (c) 2019-2020, The Cirquity Developers
//
// Please see the included LICENSE file for more information.

#pragma once

#include <config/WalletConfig.h>

namespace ApiConstants
{
    /* The number of iterations of PBKDF2 to perform on the wallet
       password. */
    const uint64_t PBKDF2_ITERATIONS = 10000;

    /* The length of the address after removing the prefix */
    const uint16_t addressBodyLength = WalletConfig::standardAddressLength - WalletConfig::addressPrefix.length();

    /* This is the equivalent of CIRQ[a-zA-Z0-9]{95} but working for all coins */
    const std::string addressRegex =
        std::string(WalletConfig::addressPrefix) + "[a-zA-Z0-9]{" + std::to_string(addressBodyLength) + "}";

    /* 64 char, hex */
    const std::string hashRegex = "[a-fA-F0-9]{64}";
} // namespace ApiConstants
