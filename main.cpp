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

                if(sb.solveBoard()){
                    std::cout << "Your puzzle has been solved" << std::endl;
                    UserHandler::getHandler()->successfulBoardCreation(sb);
                }else{
                    std::cout << "Your board was not solvable" << std::endl;
                }

            }catch (const std::exception &e){
                std::cout << e.what() << std::endl;
            } 

        }else if(userChoice == 2){
            std::string fileName = UserHandler::getHandler()->getFileName();
            std::cout << "\n";
            try{
                std::ifstream boardInFile;
                boardInFile.open(fileName);
                if(!boardInFile){
                    throw std::runtime_error("File does not exist.");
                }
                UserHandler::getHandler()->setInput(boardInFile);
                SudokuBoard sb = UserHandler::getHandler()->inputBoard();

                if(sb.solveBoard()){
                    std::cout << "Your puzzle has been solved\n" << std::endl;
                    UserHandler::getHandler()->successfulBoardCreation(sb);
                }else{
                    std::cout << "Your board was not solvable\n" << std::endl;
                }
            }catch (const std::exception &e){
                std::cout << e.what() << std::endl;
            } 

        }else if(userChoice == 3){

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
            std::cout << "Your board has been created!\n" << std::endl;
            UserHandler::getHandler()->successfulBoardCreation(sb);
        }
    }
    return 0;
}

#endif