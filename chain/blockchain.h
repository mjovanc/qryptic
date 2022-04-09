#ifndef CHAIN_BLOCKCHAIN_H
#define CHAIN_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "block.h"

class Blockchain
{
    public:
        Blockchain();

        void add_block(Block block);
        //TODO: void add_transaction(Transaction transaction);

    private:
        uint32_t n_difficulty;
        std::vector<Block> v_chain;

        Block get_last_block() const;
};

#endif