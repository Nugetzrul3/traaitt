// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2018-2020, The TurtleCoin Developers 
// Copyright (c) 2020, TRRXITTE inc.
//
// Please see the included LICENSE file for more information.

#pragma once

#include "CryptoNoteBasic.h"
#include "serialization/BinaryInputStreamSerializer.h"
#include "serialization/BinaryOutputStreamSerializer.h"
#include "serialization/CryptoNoteSerialization.h"

#include <boost/utility/value_init.hpp>

namespace Logging
{
    class ILogger;
}

namespace CryptoNote
{
    bool is_out_to_acc(
        const AccountKeys &acc,
        const KeyOutput &out_key,
        const Crypto::KeyDerivation &derivation,
        size_t keyIndex);

    bool lookup_acc_outs(
        const AccountKeys &acc,
        const Transaction &tx,
        const Crypto::PublicKey &tx_pub_key,
        std::vector<size_t> &outs,
        uint64_t &money_transfered);

    bool lookup_acc_outs(
        const AccountKeys &acc,
        const Transaction &tx,
        std::vector<size_t> &outs,
        uint64_t &money_transfered);

    bool get_tx_fee(const Transaction &tx, uint64_t &fee);

    uint64_t get_tx_fee(const Transaction &tx);

    bool generate_key_image_helper(
        const AccountKeys &ack,
        const Crypto::PublicKey &tx_public_key,
        size_t real_output_index,
        KeyPair &in_ephemeral,
        Crypto::KeyImage &ki);

    bool checkInputTypesSupported(const TransactionPrefix &tx);

    bool checkOutsValid(const TransactionPrefix &tx, std::string *error = nullptr);

    bool checkInputsOverflow(const TransactionPrefix &tx);

    bool checkOutsOverflow(const TransactionPrefix &tx);

    std::vector<uint32_t> relativeOutputOffsetsToAbsolute(const std::vector<uint32_t> &off);

    std::vector<uint32_t> absolute_output_offsets_to_relative(const std::vector<uint32_t> &off);

    uint64_t getInputAmount(const Transaction &transaction);

    std::vector<uint64_t> getInputsAmounts(const Transaction &transaction);

    uint64_t getOutputAmount(const Transaction &transaction);

    void decomposeAmount(uint64_t amount, uint64_t dustThreshold, std::vector<uint64_t> &decomposedAmounts);

    // 62387455827 -> 455827 + 7000000 + 80000000 + 300000000 + 2000000000 + 60000000000, where 455827 <= dust_threshold
    template<typename chunk_handler_t, typename dust_handler_t>
    void decompose_amount_into_digits(
        uint64_t amount,
        uint64_t dust_threshold,
        const chunk_handler_t &chunk_handler,
        const dust_handler_t &dust_handler)
    {
        if (0 == amount)
        {
            return;
        }

        bool is_dust_handled = false;
        uint64_t dust = 0;
        uint64_t order = 1;
        while (0 != amount)
        {
            uint64_t chunk = (amount % 10) * order;
            amount /= 10;
            order *= 10;

            if (dust + chunk <= dust_threshold)
            {
                dust += chunk;
            }
            else
            {
                if (!is_dust_handled && 0 != dust)
                {
                    dust_handler(dust);
                    is_dust_handled = true;
                }
                if (0 != chunk)
                {
                    chunk_handler(chunk);
                }
            }
        }

        if (!is_dust_handled && 0 != dust)
        {
            dust_handler(dust);
        }
    }

} // namespace CryptoNote
