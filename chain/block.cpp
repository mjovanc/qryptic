#include <sstream>
#include "block.h"
#include "../crypto/sha256.h"

Block::Block(uint32_t n_index_in, const std::string &s_data_in) :
        m_index(n_index_in), m_data(s_data_in)
{
    m_nonce = -1;
    m_time = time(nullptr);
}

uint32_t Block::get_index()
{
    return m_index;
}

std::string Block::get_hash()
{
    return m_hash;
}

std::string Block::get_data()
{
    return m_data;
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
        m_nonce++;
        m_hash = calculate_hash();
    } while (m_hash.substr(0, n_difficulty) != str);

    std::cout << "Block mined: " << m_hash << std::endl;
}

inline std::string Block::calculate_hash() const
{
    std::stringstream ss;
    ss << m_index << m_time << m_data << m_nonce << m_prev_hash;

    return sha256(ss.str());
}