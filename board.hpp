// The overal sudoko board
// 9x9
// Each square is represented as a box object from box.hpp
#ifndef BOARD.HPP
#define BOARD.HPP
#include <map>
#include <vector>
#include "box.hpp"

class SudokuBoard {
    private:
        // holds the information for each row/col/grid values already in the board for quick access
        std::map<int, std::vector<int>> gridDictionary;
        std::map<int, std::vector<int>> rowDictionary;
        std::map<int, std::vector<int>> colDictionary;

        // number of open spaces still on the board
        int openSpaces;

        // the actual board containing the boxes and box data
        Box board[9][9];

    public:
        SudokuBoard(int initial_board[9][9]); 
        void updateDomains(int row, int col);
        void updateDegrees(int row, int col);
};

#endif