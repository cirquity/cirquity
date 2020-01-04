// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2018-2019, The TurtleCoin Developers
// Copyright (c) 2019-2020, The Cirquity Developers
//
// Please see the included LICENSE file for more information.

#pragma once

#include <string>
#include <system_error>

namespace Tools
{
    std::string getDefaultDataDirectory();

    std::string get_os_version_string();

    bool create_directories_if_necessary(const std::string &path);

    bool directoryExists(const std::string &path);
} // namespace Tools
