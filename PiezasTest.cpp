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

/**********PieceAt**********/
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
            ASSERT_EQ(p.pieceAt(i,j), Blank);
        }
    }
    ASSERT_TRUE(true);
}


/****************Drop Piece****************/

TEST(PiezasTest, DropOne)
{
    Piezas p;
    ASSERT_EQ(p.pieceAt(0,0), p.dropPiece(0));
}

TEST(PiezasTest, DropTwoSameCol)
{
    Piezas p;
    ASSERT_EQ(p.pieceAt(0,0), p.dropPiece(0));
    ASSERT_EQ(p.pieceAt(1,0), p.dropPiece(0));
}

TEST(PiezasTest, DropThreeSameCol)
{
    Piezas p;
    ASSERT_EQ(p.pieceAt(0,0), p.dropPiece(0));
    ASSERT_EQ(p.pieceAt(1,0), p.dropPiece(0));
    ASSERT_EQ(p.pieceAt(2,0), p.dropPiece(0));
}

TEST(PiezasTest, DropFourSameCol)
{
    Piezas p;
    ASSERT_EQ(p.pieceAt(0,0), p.dropPiece(0));
    ASSERT_EQ(p.pieceAt(1,0), p.dropPiece(0));
    ASSERT_EQ(p.pieceAt(2,0), p.dropPiece(0));

    ASSERT_EQ(p.dropPiece(0), Blank);
}

TEST(PiezasTest, Dropn1)
{
    Piezas p;
    ASSERT_EQ(p.dropPiece(-1), Invalid);
}

TEST(PiezasTest, Dropn4)
{
    Piezas p;
    ASSERT_EQ(p.dropPiece(4), Invalid);
}

/******************Reset******************/

TEST(PiezasTest, ResetAfter0)
{
    Piezas p;
    p.reset();
    for (int i=0; i < BOARD_ROWS; ++i) {
        for (int j=0; j < BOARD_COLS; ++j) {
            ASSERT_EQ(p.pieceAt(i, j), Blank);
        }
    }
}

TEST(PiezasTest, ResetAfterFULL)
{
    Piezas p;
    ASSERT_EQ(p.pieceAt(0,0), p.dropPiece(0));
    ASSERT_EQ(p.pieceAt(1,0), p.dropPiece(0));
    ASSERT_EQ(p.pieceAt(2,0), p.dropPiece(0));

    ASSERT_EQ(p.pieceAt(0,1), p.dropPiece(1));
    ASSERT_EQ(p.pieceAt(1,1), p.dropPiece(1));
    ASSERT_EQ(p.pieceAt(2,1), p.dropPiece(1));

    ASSERT_EQ(p.pieceAt(0,2), p.dropPiece(2));
    ASSERT_EQ(p.pieceAt(1,2), p.dropPiece(2));
    ASSERT_EQ(p.pieceAt(2,2), p.dropPiece(2));

    ASSERT_EQ(p.pieceAt(0,3), p.dropPiece(3));
    ASSERT_EQ(p.pieceAt(1,3), p.dropPiece(3));
    ASSERT_EQ(p.pieceAt(2,3), p.dropPiece(3));

    p.reset();
    for (int i=0; i < BOARD_ROWS; ++i) {
        for (int j=0; j < BOARD_COLS; ++j) {
            ASSERT_EQ(p.pieceAt(i, j), Blank);
        }
    }
}

TEST(PiezasTest, ResetAfterFullPlacment)
{
    Piezas p;

    ASSERT_EQ(p.pieceAt(0,2), p.dropPiece(2));
    ASSERT_EQ(p.pieceAt(1,2), p.dropPiece(2));
    ASSERT_EQ(p.pieceAt(2,2), p.dropPiece(2));

    ASSERT_EQ(Blank, p.dropPiece(2));

    p.reset();
    for (int i=0; i < BOARD_ROWS; ++i) {
        for (int j=0; j < BOARD_COLS; ++j) {
            ASSERT_EQ(p.pieceAt(i, j), Blank);
        }
    }
}

TEST(PiezasTest, ResetAfterBadPlacment)
{
    Piezas p;


    ASSERT_EQ(Invalid, p.dropPiece(4));

    p.reset();
    for (int i=0; i < BOARD_ROWS; ++i) {
        for (int j=0; j < BOARD_COLS; ++j) {
            ASSERT_EQ(p.pieceAt(i, j), Blank);
        }
    }
}

