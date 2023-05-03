#ifndef BOARDFACTORY_HPP
#define BOARDFACTORY_HPP
#include "board.hpp"
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cstddef>
#include <fstream>


enum boardDifficulty {
    easy = 38,
    medium = 33,
    hard = 28
};

class BoardFactory {
    public:

        // returns a Sudoku board from an array
        static SudokuBoard createBoard(int arr[SIZE * SIZE]);


        // returns a randomly generated board of different difficulty (*** UNFINISHED ***);
        static SudokuBoard createBoard(boardDifficulty difficulty);
        static void rowSwap(int arr[SIZE * SIZE], int r1, int r2);
        static void colSwap(int arr[SIZE * SIZE], int c1, int c2);

        // Ported over to UserHandler to follow the design patterns
        // returns a board from either a file or from user input (strategy design pattern)
        // static SudokuBoard solveBoardFromFile(std::string fileName);
        // static SudokuBoard solveBoardFromInput();
};

#endif