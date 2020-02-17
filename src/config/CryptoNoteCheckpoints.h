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
            {10000, "2e49f0646ae1dcaba403a141da1a0184b72da558b9449e4f6c35e0ede3cc8c19"},
            {15000, "241b881d95a7c04e921ca15b1cb9a55176fce0382ded99c25e435d37d062fec8"},
            {20000, "fce5ff1e6777bc2a1336943f7952e94cd0d502e14cb9705338120b22d55e9929"},
            {25000, "abb7f9995e68334adc29f66696f07f5fdf385792d7537a24f0aeee6f1194b6a7"},
            {30000, "96b98509f10c9cec17747d7ebfdd538ac3ace7c0da51dcda8ae50d201da63134"},
            {35000, "9905a3efa0cd252468abb77a8b4368f8e1a663a6a20ade682d2a90ec3bab4697"},
            {40000, "328bd494e265742bcbe6da2c4b9b6cc6994d40c8775bc0cf6c6d2015522ffb08"},
            {45000, "b957db438ad761c625455089d50cd2a70e52767556f9de9aa6ad3b3110f2d2f2"},
            {50000, "fad41f77a0f1636ba04ecea708470eb20f089d5547daaa19adfcfad6ac247042"}
    };
} // namespace CryptoNote
