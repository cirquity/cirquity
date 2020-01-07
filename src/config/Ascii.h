// Copyright (c) 2018, The TurtleCoin Developers
// Copyright (c) 2019-2020, The Cirquity Developers
//
// Please see the included LICENSE file for more information

#pragma once

#include <string>

const std::string windowsAsciiArt = "\n"
                                    "   _____ _____ _____   ____  _    _ _____ _________     __\n"
                                    "  / ____|_   _|  __ \\ / __ \\| |  | |_   _|__   __\\ \\   / /\n"
                                    " | |      | | | |__) | |  | | |  | | | |    | |   \\ \\_/ / \n"
                                    " | |      | | |  _  /| |  | | |  | | | |    | |    \\   /  \n"
                                    " | |____ _| |_| | \\ \\| |__| | |__| |_| |_   | |     | |   \n"
                                    "  \\_____|_____|_|  \\_\\\\___\\_\\\\____/|_____|  |_|     |_|   \n"
                                    "                                                          \n";

const std::string nonWindowsAsciiArt =
        "\n                                                        \n"
        " ██████╗██╗██████╗  ██████╗ ██╗   ██╗██╗████████╗██╗   ██╗\n"
        "██╔════╝██║██╔══██╗██╔═══██╗██║   ██║██║╚══██╔══╝╚██╗ ██╔╝\n"
        "██║     ██║██████╔╝██║   ██║██║   ██║██║   ██║    ╚████╔╝ \n"
        "██║     ██║██╔══██╗██║▄▄ ██║██║   ██║██║   ██║     ╚██╔╝  \n"
        "╚██████╗██║██║  ██║╚██████╔╝╚██████╔╝██║   ██║      ██║   \n"
        " ╚═════╝╚═╝╚═╝  ╚═╝ ╚══▀▀═╝  ╚═════╝ ╚═╝   ╚═╝      ╚═╝   \n";

/* Windows has some characters it won't display in a terminal. If your ascii
   art works fine on Windows and Linux terminals, just replace 'asciiArt' with
   the art itself, and remove these two #ifdefs and above ascii arts */
#ifdef _WIN32

const std::string asciiArt = windowsAsciiArt;

#else
const std::string asciiArt = nonWindowsAsciiArt;
#endif
