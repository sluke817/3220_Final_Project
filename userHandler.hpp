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
        static UserHandler* instance; // Singleton design pattern
        std::ostream* outputStream;
        std::istream* inputStream;
        UserHandler(std::istream&, std::ostream&);
    public:
        static UserHandler* getHandler();
        int getMenuChoice(int, std::string);

        void setInput(std::istream&);
        SudokuBoard inputBoard();

        void setOutput(std::ostream&); // Strategy design pattern
        void outputBoard(SudokuBoard&);
};


#endif