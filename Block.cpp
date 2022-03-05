#include <sstream>
#include "Block.h"
#include "sha256.h"

Block::Block(uint32_t nIndexIn, const std::string &sDataIn) : 
    nIndex(nIndexIn), sData(sDataIn)
{
    nNonce = -1;
    tTime = time(nullptr);
}

std::string Block::getHash()
{
    return sHash;
}

void Block::mineBlock(uint32_t nDifficulty)
{
    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

    std::string str(cstr);

    do
    {
        nNonce++;
        sHash = calculateHash();
    } while (sHash.substr(0, nDifficulty) != str);

    std::cout << "Block mined: " << sHash << std::endl;
}

inline std::string Block::calculateHash() const
{
    std::stringstream ss;
    ss << nIndex << tTime << sData << nNonce << sPrevHash;

    return sha256(ss.str());
}