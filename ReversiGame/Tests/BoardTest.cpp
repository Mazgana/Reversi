#include <gtest/gtest.h>
#include "Board.h"

using namespace std;

class BoardTest: public testing::Test {
protected:
    Board brd, setBrd;
public:
    BoardTest(): brd(), setBrd(4,4) {
    }
    virtual void SetUp() {
        brd.initialize();
        setBrd.initialize();
        setBrd.putChip(BLACK,1,2);
        setBrd.putChip(WHITE, 1,3);
    }
};

TEST_F(BoardTest, puttingAndRevealingChips) {
    EXPECT_EQ(setBrd.reveal(1,2),setBrd.reveal(3,2));
    EXPECT_EQ(setBrd.reveal(1,2), BLACK);
}

TEST_F(BoardTest, flippingNearChipsTest) {
    EXPECT_EQ(setBrd.reveal(2,2),BLACK);
    EXPECT_EQ(setBrd.reveal(2,3), WHITE);
}

TEST_F(BoardTest, fullBoardTest) {
    setBrd.putChip(BLACK,1,2);
    setBrd.putChip(WHITE, 1,1);
    setBrd.putChip(BLACK,2,1);
    setBrd.putChip(WHITE, 1,3);
    setBrd.putChip(BLACK,1,4);
    setBrd.putChip(WHITE, 3,1);
    setBrd.putChip(BLACK,4,1);
    setBrd.putChip(WHITE, 2,4);
    setBrd.putChip(BLACK,3,4);
    setBrd.putChip(WHITE, 4,2);
    setBrd.putChip(BLACK,4,3);
    setBrd.putChip(WHITE, 4,4);

    EXPECT_EQ(setBrd.getWinner(), WHITE);
}
