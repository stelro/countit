#ifndef GUARD_ERROR_HANDLING_H
#define GUARD_ERROR_HANDLING_H

#include <iostream>

namespace stel {

    class InitializerException {
    private:
        std::string message;
        std::string error_function;
    public:
        InitializerException();
        InitializerException(const std::string &msg, const std::string &fnc);
    public:
        void What() const;

    };

}

#endif
