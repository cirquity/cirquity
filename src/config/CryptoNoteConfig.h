// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2014-2018, The Monero Project
// Copyright (c) 2018-2019, The TurtleCoin Developers
// Copyright (c) 2019-2020, The Cirquity Developers
//
// Please see the included LICENSE file for more information.

#pragma once

#include <boost/uuid/uuid.hpp>
#include <crypto/hash.h>
#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <limits>
#include <string>

namespace CryptoNote
{
    namespace parameters
    {
        const uint64_t DIFFICULTY_TARGET = 30; // seconds

        const uint32_t CRYPTONOTE_MAX_BLOCK_NUMBER = 500000000;

        const size_t CRYPTONOTE_MAX_BLOCK_BLOB_SIZE = 500000000;

        const size_t CRYPTONOTE_MAX_TX_SIZE = 1000000000;

        const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 3934293; // cirq

        const uint32_t CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW = 40;

        const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT = 60 * 60 * 2;

        const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V3 = 3 * DIFFICULTY_TARGET;

        const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V4 = 6 * DIFFICULTY_TARGET;

        const size_t BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW = 60;

        const size_t BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW_V3 = 11;

        // MONEY_SUPPLY - total number coins to be generated
        const uint64_t MONEY_SUPPLY = UINT64_C(100000000000000);

        const uint32_t ZAWY_DIFFICULTY_BLOCK_INDEX = 187000;

        const size_t ZAWY_DIFFICULTY_V2 = 0;

        const uint8_t ZAWY_DIFFICULTY_DIFFICULTY_BLOCK_VERSION = 3;

        const uint64_t LWMA_2_DIFFICULTY_BLOCK_INDEX = 620000;

        const uint64_t LWMA_2_DIFFICULTY_BLOCK_INDEX_V2 = 700000;

        const uint64_t LWMA_2_DIFFICULTY_BLOCK_INDEX_V3 = 800000;

        const unsigned EMISSION_SPEED_FACTOR = 25;

        static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

        const char GENESIS_COINBASE_TX_HEX[] =
                "012801ff000183b1de16029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd08807121010ca9abb3d1bdf7d4"
                "a86cbb2861c03f9c430ee2e1ce9528f1bb7b87a9b2180e40";

        static_assert(
            sizeof(GENESIS_COINBASE_TX_HEX) / sizeof(*GENESIS_COINBASE_TX_HEX) != 1,
            "GENESIS_COINBASE_TX_HEX must not be empty.");

        /* This is the unix timestamp of the first "mined" block (technically block 2, not the genesis block)
           You can get this value by doing "print_block 2" in cirquityd. It is used to know what timestamp
           to import from when the block height cannot be found in the node or the node is offline. */
        const uint64_t GENESIS_BLOCK_TIMESTAMP = 1579553288;

        const size_t CRYPTONOTE_REWARD_BLOCKS_WINDOW = 100;

        const size_t CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE =
            100000; // size of block (bytes) after which reward for block calculated using block size
        const size_t CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2 = 20000;

        const size_t CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1 = 10000;

        const size_t CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;

        const size_t CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE = 600;

        const size_t CRYPTONOTE_DISPLAY_DECIMAL_POINT = 2;

        /* TODO: Remove? */
        const uint64_t MINIMUM_FEE = UINT64_C(10);

        /* Fee per byte is rounded up in chunks. This helps makes estimates
         * more accurate. It's suggested to make this a power of two, to relate
         * to the underlying storage cost / page sizes for storing a transaction. */
        const uint64_t FEE_PER_BYTE_CHUNK_SIZE = 256;

        /* Fee to charge per byte of transaction. Will be applied in chunks, see
         * above. This value comes out to 1.953125. We use this value instead of
         * something like 2 because it makes for pretty resulting fees
         * - 5 CIRQ vs 5.12 CIRQ. You can read this as.. the fee per chunk
         * is 500 atomic units. The fee per byte is 500 / chunk size. */
        const double MINIMUM_FEE_PER_BYTE_V1 = 500.00 / FEE_PER_BYTE_CHUNK_SIZE;
        
        /* Height for our first fee to byte change to take effect. */
        const uint64_t MINIMUM_FEE_PER_BYTE_V1_HEIGHT = 2200000;

        /* This section defines our minimum and maximum mixin counts required for transactions */
        const uint64_t MINIMUM_MIXIN_V1 = 0;

        const uint64_t MAXIMUM_MIXIN_V1 = 100;

        const uint64_t MINIMUM_MIXIN_V2 = 0;

        const uint64_t MAXIMUM_MIXIN_V2 = 3;

        const uint64_t MINIMUM_MIXIN_V3 = 0;

        const uint64_t MAXIMUM_MIXIN_V3 = 3;

        /* The heights to activate the mixin limits at */
        const uint32_t MIXIN_LIMITS_V1_HEIGHT = 1000;

        const uint32_t MIXIN_LIMITS_V2_HEIGHT = 620000;

        const uint32_t MIXIN_LIMITS_V3_HEIGHT = 800000;

        /* The mixin to use by default with zedwallet and cirquity-service */
        /* DEFAULT_MIXIN_V0 is the mixin used before MIXIN_LIMITS_V1_HEIGHT is started */
        const uint64_t DEFAULT_MIXIN_V0 = 3;

        const uint64_t DEFAULT_MIXIN_V1 = 1;

        const uint64_t DEFAULT_MIXIN_V2 = 1;

        const uint64_t DEFAULT_MIXIN_V3 = 3;

        const uint64_t DEFAULT_DUST_THRESHOLD = UINT64_C(10);

        const uint64_t DEFAULT_DUST_THRESHOLD_V2 = UINT64_C(0);

        const uint32_t DUST_THRESHOLD_V2_HEIGHT = MIXIN_LIMITS_V2_HEIGHT;

        const uint32_t FUSION_DUST_THRESHOLD_HEIGHT_V2 = 800000;

        const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY = 24 * 60 * 60 / DIFFICULTY_TARGET;

        const size_t DIFFICULTY_WINDOW = 17;

        const size_t DIFFICULTY_WINDOW_V1 = 2880;

        const size_t DIFFICULTY_WINDOW_V2 = 2880;

        const uint64_t DIFFICULTY_WINDOW_V3 = 60;

        const uint64_t DIFFICULTY_BLOCKS_COUNT_V3 = DIFFICULTY_WINDOW_V3 + 1;

        const size_t DIFFICULTY_CUT = 0; // timestamps to cut after sorting
        const size_t DIFFICULTY_CUT_V1 = 60;

        const size_t DIFFICULTY_CUT_V2 = 60;

        const size_t DIFFICULTY_LAG = 0; // !!!
        const size_t DIFFICULTY_LAG_V1 = 15;

        const size_t DIFFICULTY_LAG_V2 = 15;

        static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

        const size_t MAX_BLOCK_SIZE_INITIAL = 100000;

        const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR = 100 * 1024;

        const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

        const uint64_t MAX_EXTRA_SIZE = 140000;

        const uint64_t MAX_EXTRA_SIZE_V2 = 1024;

        const uint64_t MAX_EXTRA_SIZE_V2_HEIGHT = 1000;

        /* 25 trillion atomic, or 250 billion CIRQ -> Max supply / mixin+1 outputs */
        /* This is enforced on the daemon side. An output > 250 billion causes
         * an invalid block. */
        const uint64_t MAX_OUTPUT_SIZE_NODE   = 250'000'000'000'00;

        /* 100 billion atomic, or 1 billion CIRQ */
        /* This is enforced on the client side. An output > 1 billion will not
         * be created in a transaction */
        const uint64_t MAX_OUTPUT_SIZE_CLIENT = 1'000'000'000'00;

        const uint64_t MAX_OUTPUT_SIZE_HEIGHT = 20000;

        /* For new projects forked from this code base, the values immediately below
           should be changed to 0 to prevent issues with transaction processing
           and other possible unexpected behavior */
        const uint64_t TRANSACTION_SIGNATURE_COUNT_VALIDATION_HEIGHT = 1400000;

        const uint64_t BLOCK_BLOB_SHUFFLE_CHECK_HEIGHT = 1600000;

        const uint64_t TRANSACTION_INPUT_BLOCKTIME_VALIDATION_HEIGHT = 1600000;

        /* This describes how many blocks of "wiggle" room transactions have regarding
           when the outputs can be spent based on a reasonable belief that the outputs
           would unlock in the current block period */
        const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS = 1;

        const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS =
            DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

        const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME = 60 * 60 * 24; // seconds, one day
        const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 7; // seconds, one week
        const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL =
            7; // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to
               // forget tx

        const size_t FUSION_TX_MAX_SIZE = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT * 30 / 100;

        const size_t FUSION_TX_MIN_INPUT_COUNT = 12;

        const size_t FUSION_TX_MIN_IN_OUT_COUNT_RATIO = 4;

        /* This sets the maximum number of fusion transactions that can be present in the pool
           at any given time. Incoming fusion transactions that attempt to exceed this limit
           will be rejected from the pool and will not be added. This mechanism is in place
           to help curtail fusion transaction spam. */
        const size_t FUSION_TX_MAX_POOL_COUNT = 20;

        const size_t NORMAL_TX_MAX_OUTPUT_COUNT_V1 = 90;

        const size_t NORMAL_TX_MAX_OUTPUT_COUNT_V1_HEIGHT = 2200000;

        const uint32_t UPGRADE_HEIGHT_V2 = 1;

        const uint32_t UPGRADE_HEIGHT_V3 = 2;

        const uint32_t UPGRADE_HEIGHT_V4 = 35000; // Upgrade height for CN-Lite Variant 1 switch.

        const uint32_t UPGRADE_HEIGHT_V5 = 500000; // Upgrade height for CN-Turtle Variant 2 switch.

        const uint32_t UPGRADE_HEIGHT_V6 = 1000000; // Upgrade height for Chukwa switch.

        const uint32_t UPGRADE_HEIGHT_CURRENT = UPGRADE_HEIGHT_V6;

        const unsigned UPGRADE_VOTING_THRESHOLD = 90; // percent
        const uint32_t UPGRADE_VOTING_WINDOW = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
        const uint32_t UPGRADE_WINDOW = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
        static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
        static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

        /* Block heights we are going to have hard forks at */
        const uint64_t FORK_HEIGHTS[] = {
            187000, // 0
            350000, // 1
            440000, // 2
            620000, // 3
            700000, // 4
            800000, // 5
            1000000, // 6
            1200000, // 7
            1300000, // 8
            1400000, // 9
            1600000, // 10
            1800000, // 11
            2000000, // 12
            2200000, // 13
            2400000, // 14
            2600000, // 15
            2800000, // 16
            3000000, // 17
        };

        /* MAKE SURE TO UPDATE THIS VALUE WITH EVERY MAJOR RELEASE BEFORE A FORK */
        const uint64_t SOFTWARE_SUPPORTED_FORK_INDEX = 13;

        const uint64_t FORK_HEIGHTS_SIZE = sizeof(FORK_HEIGHTS) / sizeof(*FORK_HEIGHTS);

        /* The index in the FORK_HEIGHTS array that this version of the software will
           support. For example, if CURRENT_FORK_INDEX is 3, this version of the
           software will support the fork at 600,000 blocks.

           This will default to zero if the FORK_HEIGHTS array is empty, so you don't
           need to change it manually. */
        const uint8_t CURRENT_FORK_INDEX = FORK_HEIGHTS_SIZE == 0 ? 0 : SOFTWARE_SUPPORTED_FORK_INDEX;

        /* Make sure CURRENT_FORK_INDEX is a valid index, unless FORK_HEIGHTS is empty */
        static_assert(
            FORK_HEIGHTS_SIZE == 0 || CURRENT_FORK_INDEX < FORK_HEIGHTS_SIZE,
            "CURRENT_FORK_INDEX out of range of FORK_HEIGHTS!");

        const char CRYPTONOTE_BLOCKS_FILENAME[] = "blocks.bin";

        const char CRYPTONOTE_BLOCKINDEXES_FILENAME[] = "blockindexes.bin";

        const char CRYPTONOTE_POOLDATA_FILENAME[] = "poolstate.bin";

        const char P2P_NET_DATA_FILENAME[] = "p2pstate.bin";

        const char MINER_CONFIG_FILE_NAME[] = "miner_conf.json";
    } // namespace parameters

    const char CRYPTONOTE_NAME[] = "Cirquity";

    const uint8_t TRANSACTION_VERSION_1 = 1;

    const uint8_t TRANSACTION_VERSION_2 = 2;

    const uint8_t CURRENT_TRANSACTION_VERSION = TRANSACTION_VERSION_1;

    const uint8_t BLOCK_MAJOR_VERSION_1 = 1; /* From zero */
    const uint8_t BLOCK_MAJOR_VERSION_2 = 2; /* UPGRADE_HEIGHT_V2 */
    const uint8_t BLOCK_MAJOR_VERSION_3 = 3; /* UPGRADE_HEIGHT_V3 */
    const uint8_t BLOCK_MAJOR_VERSION_4 = 4; /* UPGRADE_HEIGHT_V4 */
    const uint8_t BLOCK_MAJOR_VERSION_5 = 5; /* UPGRADE_HEIGHT_V5 */
    const uint8_t BLOCK_MAJOR_VERSION_6 = 6; /* UPGRADE_HEIGHT_V6 */

    const uint8_t BLOCK_MINOR_VERSION_0 = 0;

    const uint8_t BLOCK_MINOR_VERSION_1 = 1;

    const std::unordered_map<uint8_t, std::function<void(const void *data, size_t length, Crypto::Hash &hash)>>
        HASHING_ALGORITHMS_BY_BLOCK_VERSION = {
            {BLOCK_MAJOR_VERSION_1, Crypto::cn_slow_hash_v0}, /* From zero */
            {BLOCK_MAJOR_VERSION_2, Crypto::cn_slow_hash_v0}, /* UPGRADE_HEIGHT_V2 */
            {BLOCK_MAJOR_VERSION_3, Crypto::cn_slow_hash_v0}, /* UPGRADE_HEIGHT_V3 */
            {BLOCK_MAJOR_VERSION_4, Crypto::cn_lite_slow_hash_v1}, /* UPGRADE_HEIGHT_V4 */
            {BLOCK_MAJOR_VERSION_5, Crypto::cn_turtle_lite_slow_hash_v2}, /* UPGRADE_HEIGHT_V5 */
            {BLOCK_MAJOR_VERSION_6, Crypto::chukwa_slow_hash} /* UPGRADE_HEIGHT_V6 */
    };

    const size_t BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT = 10000; // by default, blocks ids count in synchronizing
    const uint64_t BLOCKS_SYNCHRONIZING_DEFAULT_COUNT = 100; // by default, blocks count in blocks downloading
    const size_t COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT = 1000;

    const int P2P_DEFAULT_PORT = 18129;

    const int RPC_DEFAULT_PORT = 18128;

    const int SERVICE_DEFAULT_PORT = 18127;

    const size_t P2P_LOCAL_WHITE_PEERLIST_LIMIT = 1000;

    const size_t P2P_LOCAL_GRAY_PEERLIST_LIMIT = 5000;

    // P2P Network Configuration Section - This defines our current P2P network version
    // and the minimum version for communication between nodes
    const uint8_t P2P_CURRENT_VERSION = 7;

    const uint8_t P2P_MINIMUM_VERSION = 6;

    // This defines the minimum P2P version required for lite blocks propogation
    const uint8_t P2P_LITE_BLOCKS_PROPOGATION_VERSION = 4;

    // This defines the number of versions ahead we must see peers before we start displaying
    // warning messages that we need to upgrade our software.
    const uint8_t P2P_UPGRADE_WINDOW = 2;

    const size_t P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE = 32 * 1024 * 1024; // 32 MB
    const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT = 8;

    const size_t P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT = 70;

    const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL = 60; // seconds
    const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE = 50000000; // 50000000 bytes maximum packet size
    const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE = 250;

    const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT = 5000; // 5 seconds
    const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT = 2000; // 2 seconds
    const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT = 60 * 2 * 1000; // 2 minutes
    const size_t P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT = 5000; // 5 seconds
    const char P2P_STAT_TRUSTED_PUB_KEY[] = "";

    const uint64_t DATABASE_WRITE_BUFFER_MB_DEFAULT_SIZE = 256; // 256 MB
    const uint64_t DATABASE_READ_BUFFER_MB_DEFAULT_SIZE = 128; // 128 MB
    const uint32_t DATABASE_DEFAULT_MAX_OPEN_FILES = 125; // 125 files
    const uint16_t DATABASE_DEFAULT_BACKGROUND_THREADS_COUNT = 4; // 4 DB threads

    const char LATEST_VERSION_URL[] = "http://latest.cirquity.com";

    const std::string LICENSE_URL = "https://github.com/cirquity/cirquity/blob/master/LICENSE";

    const static boost::uuids::uuid CRYPTONOTE_NETWORK = {{0x12, 0xEC, 0xD3, 0x69, 0xC8, 0x52, 0x57, 0x41, 0x64, 0xA9, 0x91, 0xA4, 0xB6, 0xC1, 0x43, 0xE9}};

    const char *const SEED_NODES[] = {
        "5.135.184.167:18129", // cirquity seed-node-1
        "5.135.185.107:18129", // cirquity seed-node-2
    };
} // namespace CryptoNote
