#include "userHandler.hpp"

UserHandler* UserHandler::instance = nullptr;

UserHandler::UserHandler(std::ostream& out) {
    outputStream = &out;
}

// default is cout, to change make sure to set the output after getting the handler
UserHandler* UserHandler::getHandler() {
    if(!instance) {
        instance = new UserHandler(std::cout);
    }
    return instance;
}

// sets the output
void UserHandler::setOutput(std::ostream& newOutputLoc) {
    outputStream = &newOutputLoc;
}

void UserHandler::outputBoard(SudokuBoard board) {
    try {
        *outputStream << board.toString();
    }
    catch(std::exception) {
        std::cout << "Error when attempting to output board." << std::endl;
    }
}



// returns a choice from a menu selection. Does not let the user leave until entering a valid choice
int UserHandler::getMenuChoice(int numChoices, std::string msg) {

    std::cout << msg << " ";

    while(true) {
        int choice = 0;
        bool validChoice = false;

        try {
            std::cin >> choice;
            std::cout << std::endl;

            for(int i = 0; i <= numChoices; i++) {
                if(choice == i) {
                    validChoice == true;
                }
            }
        }
        catch(std::exception ex) {
            validChoice == false;
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







