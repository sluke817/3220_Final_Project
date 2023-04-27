#include "boardFactory.hpp"

SudokuBoard BoardFactory::createBoard(boardDifficulty difficulty) {
    int initialValidLayout[N][N] = {{3, 1, 6, 5, 7, 8, 4, 9, 2}, 
                                    {5, 2, 9, 1, 3, 4, 7, 6, 8}, 
                                    {4, 8, 7, 6, 2, 9, 5, 3, 1}, 
                                    {2, 6, 3, 4, 1, 5, 9, 8, 7}, 
                                    {9, 7, 4, 8, 6, 3, 1, 2, 5}, 
                                    {8, 5, 1, 7, 9, 2, 6, 4, 3}, 
                                    {1, 3, 8, 9, 4, 7, 2, 5, 6}, 
                                    {6, 9, 2, 3, 5, 1, 8, 7, 4}, 
                                    {7, 4, 5, 2, 8, 6, 3, 1, 9}};

    for(int i = 0; i < (int)difficulty; i++) {
        int randomRow = rand() % 10;
        int randomCol = rand() % 10;

        initialValidLayout[randomRow][randomCol] = 0;
    }

    return SudokuBoard(initialValidLayout);
}

SudokuBoard BoardFactory::createBoard(int arr[N][N]) {
    return SudokuBoard(arr);
}

template <typename T, size_t K>
std::istream& operator>>(std::istream& is, T(&board)[K])
{
    for (size_t i = 0; i < K; ++i) {
        is >> board[i];
    }
    return is;
}

SudokuBoard BoardFactory::solveBoardFromInput(){

    std::cout << "You will enter the puzzle row by row. Enter a 0 for values that are empty" << std::endl;
    std::cout << "An example entry looks like this : 1 2 3 4 5 6 7 8 9" << std::endl;

    int row[N];
    int board[N][N];

    for(int i = 0; i < N; i++){
        std::cout << "Please enter the " << i + 1 << " row" << std::endl;
        std::cin >> row;
        for(int j = 0; j < N; j++){
            board[i][j] = row[j];
        }
    }

    SudokuBoard sb = SudokuBoard(board);
    sb.solveBoard();

    return sb;
}

SudokuBoard BoardFactory::solveBoardFromFile(std::string fileName){
    int board[9][9];
    std::ifstream infile(fileName);

    if (!infile) {
        std::cerr << "Unable to open file";
        exit(1);
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            infile >> board[i][j];
        }
    }
    SudokuBoard sb = SudokuBoard(board);
    sb.solveBoard();

    return sb;
}


