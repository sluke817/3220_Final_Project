#include "userHandler.hpp"

UserHandler* UserHandler::instance = nullptr; // for Singleton implementation

UserHandler::UserHandler(std::istream& in, std::ostream& out) {
    outputStream = &out;
    inputStream = &in;
}

// default is cout, to change make sure to set the output after getting the handler if different is desired
UserHandler* UserHandler::getHandler() {
    if(!instance) {
        instance = new UserHandler(std::cin, std::cout);
    }
    return instance;
}


// sets the output
void UserHandler::setOutput(std::ostream& newOut) {
    outputStream = &newOut;
}

// outputs a sudoku board to the output
void UserHandler::outputBoard(SudokuBoard& board) {
    try {
        *outputStream << board.toString();
    }
    catch(std::exception) {
        std::cout << "Error when attempting to output board." << std::endl;
    }
}

// cool template for overiding the >> operator to handle the reading of the board to any input stream (thanks olivia)
template <typename T, size_t K>
std::istream& operator>>(std::istream& is, T(&board)[K])
{
    for (size_t i = 0; i < K; ++i) {
        is >> board[i];
    }
    return is;
}

// sets the input (can use either cin or a ifstream (file))
void UserHandler::setInput(std::istream& newIn) {
    inputStream = &newIn;
}

// returns a created sudoku board from the UserHandler's input
SudokuBoard UserHandler::inputBoard() {
    int row[N];
    int board[N * N];

    try {
        for(int i = 0; i < N; i++){

            *inputStream >> row;

            if(inputStream->fail()) { // checks for valid numerical input
                throw "Error: Invalid input format.";
            }

            for(int j = 0; j < N; j++){
                if(row[j] > 9 || row[j] < 0) {
                    throw "Error: Invalid values in board.";
                }
                board[i * N + j] = row[j];
            }
        }
    }
    catch(std::exception) {
        throw "Error when reading input. Please make sure format is correct.";
    }

    return BoardFactory::createBoard(board);
}


// returns a choice from a menu selection. Does not let the user leave until entering a valid choice (helps with user menu creation)
int UserHandler::getMenuChoice(int numChoices, std::string msg) {

    std::cout << msg << " ";

    while(true) {
        int choice = 0;
        bool validChoice = false;

        try {
            std::cin >> choice;
            std::cout << std::endl;

            if(std::cin.fail()) {
                throw std::exception();
            }

            for(int i = 0; i <= numChoices; i++) {
                if(choice == i) {
                    validChoice = true;
                }
            }
        }
        catch(std::exception ex) {
            validChoice = false;
        }

        if(validChoice) {
            std::cout << std::endl;
            return choice;
        }
        else {
            std::cout << "Invalid choice. Please try again: ";
        }
    }
}







