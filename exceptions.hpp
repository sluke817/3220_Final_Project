#ifndef EXCP_HPP
#define EXCP_HPP
#include <string>

class InvalidBoxInput : public std::exception {
    private:
        std::string message;
    public:
        InvalidBoxInput(std::string msg) {
            message = msg;
        }
        
        const char* what() const noexcept {
            return const_cast<char*>(message.c_str());
        }

        // const char * what () const{
        //     return const_cast<char*>(message.c_str());
        // }
};

#endif