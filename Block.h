#ifndef CHAIN_BLOCK_H
#define CHAIN_BLOCK_H

#include <cstdint>
#include <iostream>

class Block
{
    public:
        std::string sPrevHash;

        Block(uint32_t nIndexIn, const std::string &sDataIn);

        std::string getHash();

        void mineBlock(uint32_t nDifficulty);

    private:
        uint32_t nIndex;
        int64_t nNonce;
        std::string sData;
        std::string sHash;
        time_t tTime;

        std::string calculateHash() const;
};

#endif