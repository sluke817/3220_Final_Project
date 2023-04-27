#ifndef BOARDFACTORY_HPP
#define BOARDFACTORY_HPP
#include "board.hpp"
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cstddef>
#include <fstream>


enum boardDifficulty {
    easy = 10,
    medum = 7,
    hard = 5
};

class BoardFactory {
    public:
        // returns a randomly generated board of different difficulty
        static SudokuBoard createBoard(boardDifficulty difficulty);
        static SudokuBoard createBoard(int arr[N][N]);

        // *** ADD *** 
        // returns a board from either a file or from user input (strategy design pattern)
        static SudokuBoard solveBoardFromFile(std::string fileName);
        static SudokuBoard solveBoardFromInput();
};

#endif