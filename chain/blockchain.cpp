#include "blockchain.h"

Blockchain::Blockchain()
{
    m_chain.emplace_back(Block(0, "Genesis Block"));
    m_difficulty = 6;
}

void Blockchain::add_block(Block block)
{
    block.m_prev_hash = get_last_block().get_hash();
    block.mine_block(m_difficulty);
    m_chain.push_back(block);
}

Block Blockchain::get_last_block() const
{
    return m_chain.back();
}