//
// Created by leah on 27/11/17.
//

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
    EXPECT_EQ(setBrd.reveal(3,2),setBrd.reveal(2,3));
    EXPECT_EQ(setBrd.reveal(1,2), BLACK);
}

TEST_F(BoardTest, flippingNearChipsTest) {
    EXPECT_EQ(setBrd.reveal(2,2),BLACK);
    EXPECT_EQ(setBrd.reveal(2,3), WHITE);
}

/*TEST_F(BoardTest, fullBoardTest) {
    setBrd.putChip(BLACK,1,4);
    setBrd.putChip(WHITE, 2,1);
    setBrd.putChip(BLACK,3,1);
    setBrd.putChip(WHITE, 1,1);
    setBrd.putChip(BLACK,4,3);
    setBrd.putChip(WHITE, 4,1);
}*/