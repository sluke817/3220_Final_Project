#include "board.hpp"

// initial setup: 1D array of numbers representing a sudoku board ([row * SIZE + col] = [row][col])
SudokuBoard::SudokuBoard(int setup[SIZE * SIZE]) {
    board = std::make_unique<int[]>(SIZE * SIZE);
    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            board[row * SIZE + col] = setup[row * SIZE + col];
        }
    }
}

int SudokuBoard::getVal(int row, int col) {
    return board[row * SIZE + col];
}

// returns the board in string format
std::string SudokuBoard::toString() {
    std::stringstream ss;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            ss << board[i * SIZE + j] << " ";
        }
        ss << "\n";
    }
    return ss.str();
}

// determines if a certain move is "safe"
bool SudokuBoard::safeMove(int row, int col, int value) {
    if(value < 1 || value > SIZE) {
        throw "Invalid value.";
    }
    if(row < 0 || row > SIZE || col < 0 || col > SIZE) {
        throw "Invalid coordinantes.";
    }

    // checks if number is already in the row
    for (int i = 0; i < SIZE; i++) {
        if (board[row * SIZE + i] == value) {
            return false;
        }      
    }
    // checks if the number is already in the column
    for (int i = 0; i < SIZE; i++) {
        if (board[i * SIZE + col] == value) {
            return false;
        }  
            
    }

    // check if number is already in its 3*3 matrix
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (board[(i + startRow) * SIZE + j + startCol] == value) {
                return false;
            }
        }
    }

    // if number does not exist yet in a proper space, assume it can work
    return true;
}

// recursive algorithm in which solves the sudoku board with backtracking
bool SudokuBoard::backtrackingSolve(int row, int col) {

    // we have reached the very end with no errors, so it is solved!
    if (row == 8 && col == SIZE)
        return true;

    // if we are on the last column, we move to the next row
    if (col == SIZE) {
        row++;
        col = 0;
    }

    // if there is already a number here, move to the next space
    if (board[row * SIZE + col] > 0)
        return backtrackingSolve(row, col + 1);

    for (int value = 1; value <= SIZE; value++) 
    {
        // Check if it is safe to place the num (1-9) in the given row and col
        // we then move to next column
        if (safeMove(row, col, value)) 
        {
              
           /* Assigning a safe move value in 
              the current (row,col)
              position of the grid
              and assuming our assigned 
              num in the position
              is correct (for now)    */
            board[row * SIZE + col] = value;
            
            //  Checking the next possibility with next column
            if (backtrackingSolve(row, col + 1)) {
                return true;
            }       
        }
        // Removes the guessed value since our assumption was wrong
        board[row * SIZE + col] = 0;
    }
    return false;
    
}

//return 1 for successful
//return 0 for unsuccessful
int SudokuBoard::solveBoard() {
    if(backtrackingSolve(0,0)) {
        return 1;
    }
    else {
        return 0;
    }
}
