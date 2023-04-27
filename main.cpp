#ifndef MAIN_CPP
#define MAIN_CPP
#include "board.hpp"
#include "boardFactory.hpp"
#include "userHandler.hpp"


int main(){

    // int initialValidLayout[9][9] =
    //         {{0,0,1,0,0,2,0,0,0},
    //         {0,0,5,0,0,6,0,3,0},
    //         {4,6,0,0,0,5,0,0,0},
    //         {0,0,0,1,0,4,0,0,0},
    //         {6,0,0,8,0,0,1,4,3},
    //         {0,0,0,0,9,0,5,0,8},
    //         {8,0,0,0,4,9,0,5,0},
    //         {1,0,0,3,2,0,0,0,0},
    //         {0,0,9,0,0,0,3,0,0}};

    // SudokuBoard board1 = SudokuBoard(initialValidLayout);

    // board1.solveBoard();

    std::cout << "Enter the board row by row, making sure to put a space between each number" << std::endl;
    SudokuBoard sb = UserHandler::getHandler()->inputBoard();
    sb.printBoard();



    return 0;
}

#endif