//
// Created by leah on 27/11/17.
//

#include <gtest/gtest.h>
#include "Cell.h"

using namespace std;

TEST(CellTest, creationTests) {
    Cell cell(1,2);
    EXPECT_EQ(cell.getCol(),2);
    EXPECT_EQ(cell.getRow(),1);
    EXPECT_EQ(cell.getStatus(),EMPTY);
}

TEST(CellTest, settingChipTests) {
    Cell cell(1,2);
    cell.setStatus(BLACK);
    EXPECT_EQ(cell.getStatus(),'X');
    EXPECT_NE(cell.getStatus(),' ');
    cell.setStatus(WHITE);
    EXPECT_EQ(cell.getStatus(),'O');
    EXPECT_NE(cell.getStatus(),' ');
    EXPECT_NE(cell.getStatus(),'X');
}

TEST(CellTest, flipTests) {
    Cell cell(1,2);
    cell.setStatus(WHITE);
    cell.flip();
    EXPECT_NE(cell.getStatus(),'O');
    EXPECT_EQ(cell.getStatus(),'X');
}