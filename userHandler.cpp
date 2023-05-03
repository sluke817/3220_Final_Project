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
    catch(std::exception&) {
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
    int row[SIZE];
    int board[SIZE * SIZE];

    try {
        for(int i = 0; i < SIZE; i++){

            *inputStream >> row;

            if(inputStream->fail()) { // checks for valid numerical input
                throw "Error: Invalid input format.";
            }

            for(int j = 0; j < SIZE; j++){
                if(row[j] > 9 || row[j] < 0) {
                    throw "Error: Invalid values in board.";
                }
                board[i * SIZE + j] = row[j];
            }
        }
    }
    catch(std::exception&) {
        throw "Error when reading input. Please make sure format is correct.";
    }

    return BoardFactory::createBoard(board);
}

// returns a choice from a menu selection. Does not let the user leave until entering a valid choice (helps with user menu creation)
int UserHandler::getMenuChoice(int numChoices, std::string msg) {

    std::cout << msg << " ";
    int choice = 0;
    bool validChoice = false;

    while (!validChoice) {
        try{
            std::cout << ">> ";
            std::cin >> choice;

            if (std::cin.fail()) {
                throw std::runtime_error("Invalid input. Please try again.");
            }

            if (choice >= 1 && choice <= numChoices) {
                validChoice = true;
            } else if (choice == 0) {
                std::cout << "Thank you for using the Sudoku Solver!" << std::endl;
                exit(0);
            } else {
                throw std::runtime_error("Invalid choice. Please try again.");
            }
        }
        catch (const std::exception &e)
        {
            std::cout << "Error " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }    
    }

    return choice;
}

// get filename from the user. User must return a file that ends in .txt
std::string UserHandler::getFileName(){
    std::cout << "Enter file name (must be .txt file) : " << std::endl;
    std::string filepath_ = "";

    while(true){
        try{
            std::cout << ">> ";
            std::cin >> filepath_;

            int dotIndex = filepath_.rfind(".");

            if (dotIndex == (int)std::string::npos)
            {
                throw std::runtime_error("Invalid file name format. Please try again");
            }
            else if(filepath_.substr(dotIndex + 1) != "txt")
            {
                throw std::runtime_error("File name does not end in .txt. Please try again");
            }
            return filepath_;
        }
        catch (const std::exception &e){
            std::cout << "Error " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return filepath_;
}

//A menu for the user after a board has been created/solved
void UserHandler::successfulBoardCreation(SudokuBoard& sb){

        std::string menuMsg = 
                                "Please choose what you would like to do \n"
                                "1. Print to the commandline \n"
                                "2. Save to file \n"
                                "3. Print and save to file \n"
                                "4. Return to main menu \n"
                                "Please enter 1-4 \n";

        int choice = UserHandler::getHandler()->getMenuChoice(4, menuMsg);
        if(choice == 1){
            std::cout << sb.toString();
        }else if(choice == 2){
            saveBoardToFile(sb);
        }else if(choice == 3){
            std::cout << sb.toString();
            saveBoardToFile(sb);
        }
}

//saves a created board to a file
void UserHandler::saveBoardToFile(SudokuBoard& sb){
    std::string fileName = UserHandler::getHandler()->getFileName();
    std::ofstream boardOutFile;
    boardOutFile.open(fileName);
    UserHandler::getHandler()->setOutput(boardOutFile);
    UserHandler::getHandler()->outputBoard(sb);
    std::cout << "Your file has been saved to " << fileName << std::endl;
}