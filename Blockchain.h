#ifndef CHAIN_BLOCKCHAIN_H
#define CHAIN_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.h"

class Blockchain
{
    public:
        Blockchain();

        void addBlock(Block block);

    private:
        uint32_t nDifficulty;
        std::vector<Block> vChain;

        Block getLastBlock() const;
};

#endif