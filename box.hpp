// Individual boxes on a soduko board
// Contains a value, a grid location coordinates, and a domain of possible values for itself
#ifndef BOX.HPP
#define BOX.HPP
#include <vector>
#include <string>
#include "exceptions.hpp"

class Box {
    private:
        // actual number inside of the box : 0-9 : 0 = empty
        int value; 

        // coordinates inside of the grid
        int rowNum;
        int colNum;

        // possible values that the box can take
        std::vector<int> domain;

        // which sub grid (3x3) the box a part of
        // 1 2 3
        // 4 5 6
        // 7 8 9
        int gridNum;

        // the "degree" is the number of other boxes that depend upon the value of this box
        // i.e number of empty boxes in its row, col, and 3x3 box
        int degree;

    public:
        Box();
        Box(int value, int rowNum, int colNum);

        // returns the possible vaules the box can take on
        std::vector<int> getRemainingValues() const;

        // getters
        int getDegree() const;
        int getValue() const;
        int getGridNum() const;
        int getRowNum() const;
        int getColNum() const;

        // setters
        void setValue(int value);
};

#endif