#include <gtest/gtest.h>
#include "../chain/blockchain.h"

class BlockchainTest : public testing::Test
{
  public:
    BlockchainTest()
    {
      
    }
};


/* TEST_F(BlockchainTest, blockchain_addblock_blockAddSuccessful)
{
  // arrange
  Blockchain bChain = Blockchain();
  Block block = Block(1, "Block 1 Data");

  // act
  bChain.add_block(block);

  // assert
  ASSERT_EQ(block.get_index(), 1);
  // ASSERT_STREQ(block.get_data(), "Block 1 Data");
} */

/* TEST_F(BlockchainTest, blockchain_getPrevBlock_prevBlockGetSuccessful)
{
  // arrange

  // act

  // assert
} */