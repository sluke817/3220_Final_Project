#include "boardFactory.hpp"

// need to build out still (*** UNFINISHED ***)
SudokuBoard BoardFactory::createBoard(boardDifficulty difficulty) {
    std::srand(std::time(nullptr));

    int initialValidLayout[SIZE * SIZE] = {3, 1, 6, 5, 7, 8, 4, 9, 2, 
                                    5, 2, 9, 1, 3, 4, 7, 6, 8, 
                                    4, 8, 7, 6, 2, 9, 5, 3, 1, 
                                    2, 6, 3, 4, 1, 5, 9, 8, 7, 
                                    9, 7, 4, 8, 6, 3, 1, 2, 5, 
                                    8, 5, 1, 7, 9, 2, 6, 4, 3, 
                                    1, 3, 8, 9, 4, 7, 2, 5, 6, 
                                    6, 9, 2, 3, 5, 1, 8, 7, 4, 
                                    7, 4, 5, 2, 8, 6, 3, 1, 9};



    /*
    for(int i = 0; i < (int)difficulty; i++) {
        int randomRow = rand() % 10;
        int randomCol = rand() % 10;

        initialValidLayout[randomRow * SIZE + randomCol] = 0;
    }
    */
   //column random swaps
    for(int i = 0; i < 9; i += 3){
        int randSeed = rand() % 6 + 1;
        switch (randSeed) {
        case 1:
            break;
        case 2:
            colSwap(initialValidLayout, i+1, i+2);
            break;
        case 3:
            colSwap(initialValidLayout, i, i+1);
            break;
        case 4:
            colSwap(initialValidLayout, i, i+1);
            colSwap(initialValidLayout, i+1, i+2);
            break;
        case 5:
            colSwap(initialValidLayout, i, i+1);
            colSwap(initialValidLayout, i, i+2);
            break;
        case 6:
            colSwap(initialValidLayout, i, i+2);
            break;
        default:
            break;
        }

    }
    //row random swaps
    for(int i = 0; i < 9; i += 3){
        int randSeed = rand() % 6 + 1;
        switch (randSeed) {
        case 1:
            break;
        case 2:
            rowSwap(initialValidLayout, i+1, i+2);
            break;
        case 3:
            rowSwap(initialValidLayout, i, i+1);
            break;
        case 4:
            rowSwap(initialValidLayout, i, i+1);
            rowSwap(initialValidLayout, i+1, i+2);
            break;
        case 5:
            rowSwap(initialValidLayout, i, i+1);
            rowSwap(initialValidLayout, i, i+2);
            break;
        case 6:
            rowSwap(initialValidLayout, i, i+2);
            break;
        default:
            break;
        }
        
    }

    for(int i = 0; i < 41; i++){
        int randSeed = rand() % 81;
        initialValidLayout[randSeed] = 0;
    }

    return SudokuBoard(initialValidLayout);
}

SudokuBoard BoardFactory::createBoard(int arr[SIZE * SIZE]) {
    return SudokuBoard(arr);
}


void BoardFactory::rowSwap(int arr[SIZE * SIZE], int r1, int r2){
    int r1arr[SIZE];
    for(int i = 0; i < SIZE; i++){
        r1arr[i] = arr[r1*SIZE + i];
        arr[r1*SIZE + i] = arr[r2*SIZE + i];
    }
    for(int i = 0; i < SIZE; i++){
        arr[r2*SIZE + i] = r1arr[i];
    }
}
void BoardFactory::colSwap(int arr[SIZE * SIZE], int c1, int c2){
    int c1arr[SIZE];

    for(int i = 0; i < SIZE; i++){
        c1arr[i] = arr[c1 + SIZE*i];
        arr[c1 + SIZE*i] = arr[c2 + SIZE*i];
    }
    for(int i = 0; i < SIZE; i++){
        arr[c2 + SIZE*i] = c1arr[i];
    }
}



// template <typename T, size_t K>
// std::istream& operator>>(std::istream& is, T(&board)[K])
// {
//     for (size_t i = 0; i < K; ++i) {
//         is >> board[i];
//     }
//     return is;
// }

// SudokuBoard BoardFactory::solveBoardFromInput(){

//     std::cout << "You will enter the puzzle row by row. Enter a 0 for values that are empty" << std::endl;
//     std::cout << "An example entry looks like this : 1 2 3 4 5 6 7 8 9" << std::endl;

//     int row[N];
//     int board[N][N];

//     for(int i = 0; i < N; i++){
//         std::cout << "Please enter the " << i + 1 << " row" << std::endl;
//         std::cin >> row;
//         for(int j = 0; j < N; j++){
//             board[i][j] = row[j];
//         }
//     }

//     SudokuBoard sb = SudokuBoard(board);
//     sb.solveBoard();

//     return sb;
// }

// SudokuBoard BoardFactory::solveBoardFromFile(std::string fileName){
//     int board[9][9];
//     std::ifstream infile(fileName);

//     if (!infile) {
//         std::cerr << "Unable to open file";
//         exit(1);
//     }

//     for (int i = 0; i < 9; ++i) {
//         for (int j = 0; j < 9; ++j) {
//             infile >> board[i][j];
//         }
//     }
//     SudokuBoard sb = SudokuBoard(board);
//     sb.solveBoard();

//     return sb;
// }


