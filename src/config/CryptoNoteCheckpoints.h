// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2019-2020, The Cirquity Developers
//
// Please see the included LICENSE file for more information.

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
            {50000, "fad41f77a0f1636ba04ecea708470eb20f089d5547daaa19adfcfad6ac247042"},
            {55000, "e0f5fca5eda6e32f157b00d1845bf293417fddd935c7845e04ef5028bf85864b"},
            {60000, "f028cb66da84d5152583bffa4871018d8648ac7eddd0f6783bab63db5ec6dc99"},
            {65000, "8016201e2fdace00febdc9a267c5914dd1545fd36f4576fb30ff321b59f883d5"},
            {70000, "aa7930d9dd9bf610af9c6cc67ef0a13d2f2448f3bbc60722cb9262bfbab81620"},
            {75000, "a033c1f9cbafdca6bb6eedeb1c9a99ded63e612cb0383ae062de80e568c04842"},
            {80000, "0de007bf0dd736b5a303bc1bcd22c0b4df72aa558634cfd714d645150d64c9b3"},
            {85000, "edebb0a708304154f64e8d527312831a7a372d9f394ca10b09940da5148ed509"},
            {90000, "ae6e54f2826aad7f9b382588f29e07e01394149309248a9c877f9e1833b21d9c"},
            {95000, "e506df18015462b7e560530552c282d3364d11325dc63eef9dd8f032d3b6c191"},
            {100000, "939e52286ff65752646882976dc65c3f8ee0b8f5d01e36c520d2457cb261ed13"},
            {105000, "0ab32f7e848ca69d805f3d26f1892e447360a2d6f8cb57017b0d9415518a13de"},
            {110000, "6a0ee6cc572ebe787230882bd60577dffcedc7c928ef0b41329e64307e192811"},
            {115000, "43d87f184597a89160150ab47173571d7a37fa4d16d359be3b93de2cf0091c36"},
            {120000, "aad696b41445daaa177c7d5a80466fcf7ce28c697882289c56b0929299502906"}
    };
} // namespace CryptoNote
