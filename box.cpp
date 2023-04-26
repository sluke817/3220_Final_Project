#include "box.hpp"

Box::Box() {
    
}
Box::Box(int _value, int _rowNum, int _colNum) {

    // valid input checking
    if(_value > 9 || _value < 0) {
        throw new InvalidBoxInput("Invalid value of " + std::to_string(_value) + ".");
    }
    if(_rowNum > 9 || _rowNum < 0) {
        throw new InvalidBoxInput("Invalid value of " + std::to_string(_rowNum) + ".");
    }
    if(_colNum > 9 || _colNum < 0) {
        throw new InvalidBoxInput("Invalid value of " + std::to_string(_colNum) + ".");
    }
    

    value = _value;
    rowNum = _rowNum;
    colNum = _colNum;
    degree = 0;

    if(value > 0) {
        domain = {};
    }
    else {
        domain = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    }

    gridNum = Helper::calcGridNum(_rowNum, _colNum);
}

std::vector<int> Box::getRemainingValues() const {
    return domain;
}

// getters
int Box::getDegree() const {
    return degree;
}
int Box::getValue() const {
    return value;
}
int Box::getGridNum() const {
    return gridNum;
}
int Box::getRowNum() const {
    return rowNum;
}
int Box::getColNum() const {
    return colNum;
}

// setters
void Box::setValue(int value) {
    
}