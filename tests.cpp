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
        }
        SudokuBoard* board1;
        int initialValidLayout[9][9] =  {{0,0,1,0,0,2,0,0,0},
                                            {0,0,5,0,0,6,0,3,0},
                                            {4,6,0,0,0,5,0,0,0},
                                            {0,0,0,1,0,4,0,0,0},
                                            {6,0,0,8,0,0,1,4,3},
                                            {0,0,0,0,9,0,5,0,8},
                                            {8,0,0,0,4,9,0,5,0},
                                            {1,0,0,3,2,0,0,0,0},
                                            {0,0,9,0,0,0,3,0,0}};
};

TEST_F(BoardTest, TestInitializeBoard) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            ASSERT_EQ(board1->getVal(i, j), initialValidLayout[i][j]);
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif