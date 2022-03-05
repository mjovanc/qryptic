#include "Blockchain.h"

Blockchain::Blockchain()
{
    vChain.emplace_back(Block(0, "Genesis Block"));
    nDifficulty = 6;
}

void Blockchain::addBlock(Block block)
{
    block.sPrevHash = getLastBlock().getHash();
    block.mineBlock(nDifficulty);
    vChain.push_back(block);
}

Block Blockchain::getLastBlock() const
{
    return vChain.back();
}