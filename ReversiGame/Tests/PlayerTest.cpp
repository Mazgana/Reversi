//
// Created by leah on 27/11/17.
//

#include <gtest/gtest.h>
#include "HumanPlayer.h"

using namespace std;

TEST(PlayerTest, player_creationTests) {
    HumanPlayer p = HumanPlayer(WHITE);
    EXPECT_EQ(p.getChip(), 'O');
    EXPECT_NE(p.getChip(),' ');
    EXPECT_NE(p.getChip(),EMPTY);
}