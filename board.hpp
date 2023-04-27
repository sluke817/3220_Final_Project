// The overal sudoko board
// 9x9
// Each square is represented as a box object from box.hpp
#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <sstream>
#include <memory>

#define N 9

class SudokuBoard {
    private:
        std::unique_ptr<std::unique_ptr<int[]>[]> board;

    public:
        SudokuBoard(int initial_board[N][N]); 
        void printBoard();
        bool safeMove(int row, int col, int value);
        bool backtrackingSolve(int row, int col);
        void solveBoard();
        std::string toString();
};

#endif