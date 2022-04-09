#ifndef CHAIN_BLOCK_H
#define CHAIN_BLOCK_H

#include <cstdint>
#include <iostream>

class Block
{
    public:
        std::string s_prev_hash;

        Block(uint32_t n_index_in, const std::string &s_data_in);

        uint32_t get_index();

        std::string get_hash();
        std::string get_data();

        void mine_block(uint32_t n_difficulty);

    private:
        uint32_t n_index;
        int64_t n_nonce;
        std::string s_data;
        std::string s_hash;
        time_t t_time;
        //TODO: should hold transaction as a vector or something here?

        std::string calculate_hash() const;
};

#endif