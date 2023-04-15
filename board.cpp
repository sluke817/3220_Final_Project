#include "board.hpp"
#include "helpers.hpp"

SudokuBoard::SudokuBoard(int initial_setup[9][9]) {
    openSpaces = 9 * 9;
    for(int row = 0; row < 9; row++) {
        for(int col = 0; col < 9; col++) {
            board[row][col] = Box(initial_setup[row][col], row, col);

            if(initial_setup[row][col] != 0) {
                openSpaces--;
                rowDictionary[row].push_back(initial_setup[row][col]);
                colDictionary[col].push_back(initial_setup[row][col]);
                gridDictionary[calcGridNum(row, col)].push_back(initial_setup[row][col]);
            }
        }
    }
    updateDomains();
    updateDegrees();
}

void SudokuBoard::updateDomains() {

}

void SudokuBoard::updateDegrees() {

}
