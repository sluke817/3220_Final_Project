#include "helpers.hpp"

int calcGridNum(int rowNum, int colNum) {
    if(rowNum < 3) {
        if(colNum < 3) {
            return 0;
        }
        else if(colNum >= 3 & colNum < 6) {
            return 1;
        }
        else {
            return 2;
        }
    }
    else if(rowNum >= 3 & rowNum < 6) {
        if(colNum < 3) {
            return 4;
        }
        else if(colNum >= 3 & colNum < 6) {
            return 5;
        }
        else {
            return 6;
        }
    }
    else {
        if(colNum < 3) {
            return 7;
        }
        else if(colNum >= 3 & colNum < 6) {
            return 8;
        }
        else {
            return 9;
        }
    }   
}
