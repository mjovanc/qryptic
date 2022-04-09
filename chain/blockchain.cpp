#include "blockchain.h"

Blockchain::Blockchain()
{
    v_chain.emplace_back(Block(0, "Genesis Block"));
    n_difficulty = 6;
}

void Blockchain::add_block(Block block)
{
    block.s_prev_hash = get_last_block().get_hash();
    block.mine_block(n_difficulty);
    v_chain.push_back(block);
}

Block Blockchain::get_last_block() const
{
    return v_chain.back();
}