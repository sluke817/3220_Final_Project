#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <filesystem>
#include <limits>
#include "boardFactory.hpp"
#include "board.hpp"

// Overall class uses the Singleton design pattern 
// Output uses the strategy design pattern
class UserHandler {
    private:
        // Singleton
        static UserHandler* instance;
        UserHandler(std::istream&, std::ostream&);

        // Strategy
        std::ostream* outputStream;
        std::istream* inputStream;
    public:

        // Singleton Design Pattern
        static UserHandler* getHandler();

        //Based of user choices 
        int getMenuChoice(int, std::string);
        std::string getFileName();
        void successfulBoardCreation(SudokuBoard&);
        void saveBoardToFile(SudokuBoard&);

        // Strategy Design Pattern
        void setInput(std::istream&);
        SudokuBoard inputBoard();

        // Strategy Design Pattern
        void setOutput(std::ostream&); 
        void outputBoard(SudokuBoard&);
};


#endif