// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstddef>
#include <initializer_list>

namespace CryptoNote
{
    struct CheckpointData
    {
        uint32_t index;
        const char *blockId;
    };

    const std::initializer_list<CheckpointData> CHECKPOINTS = {
            {0, "e0c6bc0d20a0be1ec393cff5cd6d052fd4f554a87a1fedb074dca8683d0b3603"},
            {1000, "2e6505edee5b110383381f6fc4ec47e064031a333b6e54b55b3959744ae376c1"},
            {5000, "b90860d0264c43daa7217c47c20fba6b4a32f2567c2d248b3b6c8cdb1ef888f1"},
            {10000, "2e49f0646ae1dcaba403a141da1a0184b72da558b9449e4f6c35e0ede3cc8c19"}
    };
} // namespace CryptoNote
