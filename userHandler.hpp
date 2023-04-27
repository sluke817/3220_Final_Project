#ifndef HANDLER.HPP
#define HANDLER.HPP

#include <string>
#include <iostream>
#include <sstream>
#include "board.hpp"

// Overall class uses the Singleton design pattern 
// Output uses the strategy design pattern
class UserHandler {
    private:
        static UserHandler* instance; // Singleton design pattern
        std::ostream* outputStream;
        UserHandler(std::ostream& out);
    public:
        static UserHandler* getHandler();
        int getMenuChoice(int, std::string);
        void setOutput(std::ostream& newOutputLoc); // Strategy design pattern
        void outputBoard(SudokuBoard);
};


#endif