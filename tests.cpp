#ifndef TESTS_CPP
#define TESTS_CPP
#include "board.hpp"
#include "boardFactory.hpp"
#include "userHandler.hpp"
#include "gtest/gtest.h"

class BoardTest : public ::testing::Test {
    protected:
        void SetUp() override {
            board1 = new SudokuBoard(initialValidLayout);
            unsolvableBoard = new SudokuBoard(initialUnvalidLayout);

        }
        SudokuBoard* board1;
        int initialValidLayout[81] =  {0,0,1,0,0,2,0,0,0,
                                            0,0,5,0,0,6,0,3,0,
                                            4,6,0,0,0,5,0,0,0,
                                            0,0,0,1,0,4,0,0,0,
                                            6,0,0,8,0,0,1,4,3,
                                            0,0,0,0,9,0,5,0,8,
                                            8,0,0,0,4,9,0,5,0,
                                            1,0,0,3,2,0,0,0,0,
                                            0,0,9,0,0,0,3,0,0};
        SudokuBoard* unsolvableBoard;
        int initialUnvalidLayout[81] =  {6,0,0,4,0,0,3,0,8,
                                            0,0,5,0,0,6,0,3,0,
                                            4,6,0,0,0,5,0,0,0,
                                            0,0,0,1,0,4,0,0,0,
                                            6,0,0,8,0,0,1,4,3,
                                            0,0,0,0,9,0,5,0,8,
                                            8,0,0,0,4,9,0,5,0,
                                            1,0,0,3,2,0,0,0,0,
                                            0,0,9,0,0,0,3,0,9};
};

TEST_F(BoardTest, TestInitializeBoard) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            ASSERT_EQ(board1->getVal(i, j), initialValidLayout[i * SIZE + j]);
        }
    }
}

TEST_F(BoardTest, TestGetVal) {
    ASSERT_EQ(board1->getVal(0, 0), initialValidLayout[0 * SIZE + 0]);
    ASSERT_EQ(board1->getVal(10, 10), -1);
    ASSERT_EQ(board1->getVal(-1, 3), -1);
}

TEST_F(BoardTest, TestSafeMove) {
    ASSERT_TRUE(board1->safeMove(0,0,3));
    ASSERT_FALSE(board1->safeMove(0,0,1));
    ASSERT_FALSE(board1->safeMove(0,2,1));
}

TEST_F(BoardTest, TestBackTrackingSolve) {
    ASSERT_TRUE(board1->backtrackingSolve(0,0));
    ASSERT_FALSE(unsolvableBoard->backtrackingSolve(0,0));
}

TEST_F(BoardTest, TestSolveBoard) {
    ASSERT_TRUE(board1->solveBoard());
    ASSERT_FALSE(unsolvableBoard->solveBoard());
}

TEST(UserHandlerTest, Singleton) {
    UserHandler* instance1 = UserHandler::getHandler();
    UserHandler* instance2 = UserHandler::getHandler();

    ASSERT_EQ(instance1, instance2);
}

class BoardFactoryTest : public ::testing::Test {
    protected:
        BoardFactory boardFactory;
};

TEST_F(BoardFactoryTest, CreateBoardEasyDifficulty) {
    boardDifficulty difficulty = easy;
    SudokuBoard board = boardFactory.createBoard(difficulty);
    EXPECT_TRUE(board.solveBoard());
}

TEST_F(BoardFactoryTest, CreateBoardMediumDifficulty) {
    boardDifficulty difficulty = medium;
    SudokuBoard board = boardFactory.createBoard(difficulty);
    EXPECT_TRUE(board.solveBoard());
}

TEST_F(BoardFactoryTest, CreateBoardHardDifficulty) {
    boardDifficulty difficulty = hard;
    SudokuBoard board = boardFactory.createBoard(difficulty);
    EXPECT_TRUE(board.solveBoard());
}

TEST_F(BoardFactoryTest, CreateBoardCustomLayout) {
    int customLayout[81] =  {0,0,1,0,0,2,0,0,0,
                                0,0,5,0,0,6,0,3,0,
                                4,6,0,0,0,5,0,0,0,
                                0,0,0,1,0,4,0,0,0,
                                6,0,0,8,0,0,1,4,3,
                                0,0,0,0,9,0,5,0,8,
                                8,0,0,0,4,9,0,5,0,
                                1,0,0,3,2,0,0,0,0,
                                0,0,9,0,0,0,3,0,0};
    SudokuBoard board = boardFactory.createBoard(customLayout);
    // Verify that the board has the expected layout
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j ++){
            EXPECT_EQ(board.getVal(i,j), customLayout[i * SIZE + j]);
        }
    }
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif