#include "gtest/gtest.h"
#include "Cell.h"

using namespace std;

class CellTest: public testing::Test {
protected:
    Cell c1, c2;
public:
    CellTest(): c1(1,1), c2(2,3) {}
    virtual void SetUp() {
        c1.setStatus(BLACK);
    	}
};

TEST_F(CellTest, coordinateTests) {
    EXPECT_EQ(c1.getCol(),c1.getRow());
    EXPECT_EQ(c2.getRow(),2);
    EXPECT_EQ(c2.getCol(),3);
}

TEST_F(CellTest, settingChipTests) {
    EXPECT_EQ(c2.getStatus(),EMPTY);
    EXPECT_EQ(c1.getStatus(),'X');
    EXPECT_NE(c1.getStatus(),' ');
    EXPECT_NE(c1.getStatus(),c2.getStatus());
    c1.setStatus(WHITE);
    EXPECT_EQ(c1.getStatus(),'O');
    EXPECT_NE(c1.getStatus(),' ');
    EXPECT_NE(c1.getStatus(),'X');
    c1.setStatus(EMPTY);
    EXPECT_EQ(c1.getStatus(),c2.getStatus());
}

TEST_F(CellTest, flipTests) {
    c1.flip();
    EXPECT_EQ(c1.getStatus(),'O');
    EXPECT_NE(c1.getStatus(),'X');
}
