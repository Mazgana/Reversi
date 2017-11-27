//
// Created by leah on 27/11/17.
//

#include <gtest/gtest.h>
#include "Player.h"

using namespace std;

TEST(PlayerTest, player_creationTests) {
    Player player('o');
    EXPECT_EQ(player.getChip(), 'o');
    EXPECT_NE(player.getChip(),' ');
    EXPECT_NE(player.getChip(),'x');
}