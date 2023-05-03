#ifndef MAIN_CPP
#define MAIN_CPP
#include "board.hpp"
#include "boardFactory.hpp"
#include "userHandler.hpp"


int main(){
        std::cout << "Welcome to the Sudoku Solver" << std::endl;

    while(true){


        std::string mainMenuMsg =  
                        "Please choose what you would like to do:\n"
                        "1. Input a Sudoku board through the command line.\n"
                        "2. Input a Sudoku board from a file.\n"
                        "3. Generate a random Sudoku board.\n"
                        "Enter 1-3, or 0 for done to exit.\n"; 
        
        int userChoice = UserHandler::getHandler()->getMenuChoice(3, mainMenuMsg);

        if(userChoice == 1){

            try{
            std::cout << "To enter your puzzle, enter it row by row. Enter a 0 for values that are empty" << std::endl;
            std::cout << "An example entry looks like this : 1 2 3 4 5 6 7 8 9" << std::endl;

            UserHandler::getHandler()->setInput(std::cin);
            SudokuBoard sb = UserHandler::getHandler()->inputBoard();
            UserHandler::getHandler()->successfulBoardCreation(sb);
            }catch (const std::exception &e){
                std::cout << e.what() << std::endl;
            } 

        }else if(userChoice == 2){
            std::string fileName = UserHandler::getHandler()->getFileName();

            try{
            std::ifstream boardInFile;
                boardInFile.open(fileName);
                if(!boardInFile){
                    //not incorporated in the loop. So user wont be able to try again for this specific input. WIll be taken back to the main menu. Is this okay?
                    throw std::runtime_error("File does not exist.");
                }
                UserHandler::getHandler()->setInput(boardInFile);
                SudokuBoard sb = UserHandler::getHandler()->inputBoard();
                UserHandler::getHandler()->successfulBoardCreation(sb);
            }catch (const std::exception &e){
                std::cout << e.what() << std::endl;
            } 

        }else if(userChoice == 3){
            //UserHandler::getHandler()->setInput(std::cin);
            std::string difficultyMsg =  
                        "Please choose the difficulty of your random board:\n"
                        "1. Easy (approx. 38 clues)\n"
                        "2. Medium (approx. 33 clues)\n"
                        "3. Hard (approx. 28 clues)\n"
                        "Enter 1-3, or 0 to exit program.\n"; 
            int userChoice = UserHandler::getHandler()->getMenuChoice(3, difficultyMsg);
            boardDifficulty difficulty = medium;
            if(userChoice == 1) difficulty = easy;
            else if(userChoice == 3) difficulty = hard;

            SudokuBoard sb = BoardFactory::createBoard(difficulty);
            std::cout << "Here is your randomly created board:" << std::endl;
            std::cout << sb.toString() << std::endl;
            UserHandler::getHandler()->successfulBoardCreation(sb);
        }

    }

    // input decision
    // std::ifstream boardInFile;
    // boardInFile.open("board1.txt");
    // UserHandler::getHandler()->setInput(std::cin);
    // or...
    //std::cout << "Enter the board row by row, making sure to put a space between each number" << std::endl;


    // output decision
    std::ofstream boardOutFile;
    boardOutFile.open("boardOut.txt");
    UserHandler::getHandler()->setOutput(boardOutFile);
    // or...
    // do nothing -> the default output is the screen


    try {
        std::cout << "please enter a board\n";
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