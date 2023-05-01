// The overal sudoko board
// 9x9
// Each square is represented as a box object from box.hpp
#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <sstream>
#include <memory>

#define SIZE 9


class SudokuBoard {
    private:
        // [row * N + col] = [row][col]
        std::unique_ptr<int[]> board;
    public:
        SudokuBoard(int initial_board[SIZE * SIZE]); 
        int getVal(int, int);
        // void printBoard();
        bool safeMove(int row, int col, int value);
        bool backtrackingSolve(int row, int col);
        int solveBoard();
        std::string toString();
};

#endif