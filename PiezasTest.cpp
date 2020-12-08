/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, pieceAt00)
{
    Piezas p;
    ASSERT_EQ(p.pieceAt(0,0), Blank);
}

TEST(PiezasTest, pieceAt01)
{
    Piezas p;
    ASSERT_EQ(p.pieceAt(0,1), Blank);
}

TEST(PiezasTest, pieceAt02)
{
    Piezas p;
    ASSERT_EQ(p.pieceAt(0,2), Blank);
}

TEST(PiezasTest, pieceAt03)
{
    Piezas p;
    ASSERT_EQ(p.pieceAt(0,3), Blank);
}

TEST(PiezasTest, pieceAt10)
{
    Piezas p;
    ASSERT_EQ(p.pieceAt(1,0), Blank);
}

TEST(PiezasTest, pieceAt20)
{
    Piezas p;
    ASSERT_EQ(p.pieceAt(2,0), Blank);
}

TEST(PiezasTest, pieceAt34)
{
    Piezas p;
    ASSERT_EQ(p.pieceAt(3,4), Invalid);
}

TEST(PiezasTest, pieceAtn1n1)
{
    Piezas p;
    ASSERT_EQ(p.pieceAt(-1,-1), Invalid);
}

TEST(PiezasTest, pieceAt0n1)
{
    Piezas p;
    ASSERT_EQ(p.pieceAt(0,-1), Invalid);
}

TEST(PiezasTest, pieceAtxx)
{
    Piezas p;
    ASSERT_EQ(p.pieceAt('x','x'), Invalid);
}

/***************Constructor***************/

TEST(PiezasTest, Initialization)
{
    Piezas p;
    for (int i=0; i < BOARD_ROWS; ++i){
        for (int j=0; j < BOARD_COLS; ++j){
            if (p.pieceAt(i,j) != Blank) {
                ASSERT_FALSE(true);
            }
        }
    }
    ASSERT_TRUE(true);
}
