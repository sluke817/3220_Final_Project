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

    
    // input decision
    std::ifstream boardInFile;
    boardInFile.open("board1.txt");
    UserHandler::getHandler()->setInput(boardInFile);
    // or...
    //std::cout << "Enter the board row by row, making sure to put a space between each number" << std::endl;


    // output decision
    std::ofstream boardOutFile;
    boardOutFile.open("boardOut.txt");
    UserHandler::getHandler()->setOutput(boardOutFile);
    // or...
    // do nothing -> the default output is the screen



    
    try {
        SudokuBoard sb = UserHandler::getHandler()->inputBoard();
        sb.solveBoard();
        UserHandler::getHandler()->outputBoard(sb);
    }
    catch(const char* msg) {
        std::cout << msg << std::endl;
    }


    return 0;
}

#endif