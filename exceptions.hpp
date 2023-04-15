#ifndef EXCP.HPP
#define EXCP.HPP
#include <string>

class InvalidBoxInput : public std::exception {
    private:
        std::string message;
    public:
        InvalidBoxInput(std::string msg) {
            message = msg;
        }
        char * what () {
            return const_cast<char*>(message.c_str());;
        }
};

#endif