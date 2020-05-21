// Copyright (c) 2018-2020, The TurtleCoin Developers
// Copyright (c) 2020, TRRXITTE inc. development Team
//
// Please see the included LICENSE file for more information.

#pragma once

#include "CryptoNote.h"
#include "CryptoTypes.h"

#include <cstdint>
#include <vector>

std::vector<uint8_t> getParentBlockBinaryArray(const CryptoNote::BlockTemplate &block, const bool headerOnly);

std::vector<uint8_t> getParentBlockHashingBinaryArray(const CryptoNote::BlockTemplate &block, const bool headerOnly);

std::vector<uint8_t>
    getParentBinaryArray(const CryptoNote::BlockTemplate &block, const bool hashTransaction, const bool headerOnly);

std::vector<uint8_t> getBlockHashingBinaryArray(const CryptoNote::BlockTemplate &block);

Crypto::Hash getBlockHash(const CryptoNote::BlockTemplate &block);

Crypto::Hash getMerkleRoot(const CryptoNote::BlockTemplate &block);

Crypto::Hash getBlockLongHash(const CryptoNote::BlockTemplate &block);