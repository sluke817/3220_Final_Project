#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <string>
#include <iostream>
#include <sstream>
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


        int getMenuChoice(int, std::string);

        // Strategy Design Pattern
        void setInput(std::istream&);
        SudokuBoard inputBoard();

        // Strategy Design Pattern
        void setOutput(std::ostream&); 
        void outputBoard(SudokuBoard&);
};


#endif