// The overal sudoko board
// 9x9
// Each square is represented as a box object from box.hpp
#ifndef BOARD.HPP
#define BOARD.HPP
#include <iostream>

class SudokuBoard {
    private:
        int board[9][9];

    public:
        SudokuBoard(int initial_board[9][9]); 
        void printBoard();
        bool safeMove(int row, int col, int value);
        bool backtrackingSolve(int row, int col);
        void solveBoard();
};

#endif