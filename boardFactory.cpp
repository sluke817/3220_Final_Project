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

    for(int i = 0; i < 81 - difficulty; i++){
        int randSeed = rand() % 81;
        while(initialValidLayout[randSeed] == 0){
            randSeed = (randSeed + 1) % 81;
        }

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