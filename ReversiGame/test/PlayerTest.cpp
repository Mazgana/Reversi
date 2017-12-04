#include "gtest/gtest.h"
#include "HumanPlayer.h"
#include "AI.h"

using namespace std;

class PlayerTest: public testing::Test {
protected:
    HumanPlayer hp1, hp2;
    AI aip1, aip2;
public:
    PlayerTest(): hp1(), hp2(BLACK), aip1(), aip2(WHITE) {
    }
};

TEST_F(PlayerTest, humanGettingChipsAndOpposite) {
    EXPECT_EQ(hp1.getChip(),hp2.getChip());
    EXPECT_NE(hp1.getChip(),hp2.getOppositeType());
}

TEST_F(PlayerTest, aiGettingChipsAndOpposite) {
    EXPECT_EQ(aip1.getChip(),aip2.getOppositeType());
    EXPECT_NE(aip1.getOppositeType(),aip2.getOppositeType());
}
