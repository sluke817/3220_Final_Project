#include "board.hpp"
#include <cstdlib>

enum boardDifficulty {
    easy = 10,
    medum = 7,
    hard = 5
};

class BoardFactory {
    public:
        // returns a randomly generated board of different difficulty
        static SudokuBoard createBoard(boardDifficulty difficulty);

        // *** ADD *** 
        // returns a board from either a file or from user input (strategy design pattern)
        
};