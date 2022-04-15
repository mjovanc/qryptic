#ifndef CHAIN_BLOCK_H
#define CHAIN_BLOCK_H

#include <cstdint>
#include <iostream>

class Block
{
    public:
        std::string m_prev_hash;

        Block(uint32_t n_index_in, const std::string &s_data_in);

        uint32_t get_index();

        std::string get_hash();
        std::string get_data();

        void mine_block(uint32_t n_difficulty);

    private:
        uint32_t m_index;
        int64_t m_nonce;
        std::string m_data;
        std::string m_hash;
        time_t m_time;
        //TODO: should hold transaction as a vector or something here?

        std::string calculate_hash() const;
};

#endif