//
// Created by leah on 27/11/17.
//

#include <gtest/gtest.h>
#include "Cell.h"

using namespace std;

TEST(CellTest, creationTests) {
    Cell cell(1,2);
    EXPECT_EQ(cell.getX(),1);
    EXPECT_EQ(cell.getY(),2);
    EXPECT_EQ(cell.getPos(),' ');
}

TEST(CellTest, settingChipTests) {
    Cell cell(1,2);
    cell.setPos('x');
    EXPECT_EQ(cell.getPos(),'x');
    EXPECT_NE(cell.getPos(),' ');
    EXPECT_ANY_THROW(cell.setPos('t'));
}

TEST(CellTest, flipTests) {
    Cell cell(1,2);
    cell.setPos('o');
    cell.flip();
    EXPECT_NE(cell.getPos(),'o');
    EXPECT_EQ(cell.getPos(),'x');
}