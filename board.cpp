#include "board.hpp"

// initial setup: 2D array of numbers representing a sudoku board
SudokuBoard::SudokuBoard(int initial_setup[N][N]) {
    for(int row = 0; row < N; row++) {
        for(int col = 0; col < N; col++) {
            board[row][col] = initial_setup[row][col];
        }
    }
}

// prints the board
void SudokuBoard::printBoard() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool SudokuBoard::safeMove(int row, int col, int value) {
    if(value < 1 || value > N) {
        throw "Invalid value.";
    }
    if(row < 0 || row > N || col < 0 || col > N) {
        throw "Invalid coordinantes.";
    }

    // checks if number is already in the row
    for (int i = 0; i < N; i++) {
        if (board[row][i] == value) {
            return false;
        }      
    }
    // checks if the number is already in the column
    for (int i = 0; i < N; i++) {
        if (board[i][col] == value) {
            return false;
        }  
            
    }

    // check if number is already in its 3*3 matrix
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == value) {
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
    if (row == 8 && col == N)
        return true;

    // if we are on the last column, we move to the next row
    if (col == N) {
        row++;
        col = 0;
    }

    // if there is already a number here, move to the next space
    if (board[row][col] > 0)
        return backtrackingSolve(row, col + 1);

    for (int value = 1; value <= N; value++) 
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
            board[row][col] = value;
            
            //  Checking the next possibility with next column
            if (backtrackingSolve(row, col + 1)) {
                return true;
            }       
                
        }
        // Removes the guessed value since our assumption was wrong
        board[row][col] = 0;
    }
    return false;
    
}

void SudokuBoard::solveBoard() {
    std::cout << "Initial Board: " << std::endl;
    printBoard();

    if(backtrackingSolve(0,0)) {
        std::cout << "Solved board: " << std::endl;
        printBoard();
    }
    else {
        std::cout << "No solution found. Unsolvable!" << std::endl;
    }
}
