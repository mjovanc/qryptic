#include <sstream>
#include "Block.h"
#include "sha256.h"

Block::Block(uint32_t nIndexIn, const std::string &sDataIn) : 
    n_index(nIndexIn), s_data(sDataIn)
{
    n_nonce = -1;
    t_time = time(nullptr);
}

std::string Block::get_hash()
{
    return s_hash;
}

void Block::mine_block(uint32_t n_difficulty)
{
    char cstr[n_difficulty + 1];
    for (uint32_t i = 0; i < n_difficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[n_difficulty] = '\0';

    std::string str(cstr);

    do
    {
        n_nonce++;
        s_hash = calculate_hash();
    } while (s_hash.substr(0, n_difficulty) != str);

    std::cout << "Block mined: " << s_hash << std::endl;
}

inline std::string Block::calculate_hash() const
{
    std::stringstream ss;
    ss << n_index << t_time << s_data << n_nonce << s_prev_hash;

    return sha256(ss.str());
}