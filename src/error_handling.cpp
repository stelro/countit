#include "../include/error_handling.h"

namespace stel {

    InitializerException::InitializerException(const std::string &msg, const std::string &fnc)  :
        message(msg), error_function(fnc) { }

    void InitializerException::What() const
    {
        std::cerr << "Error: " << message << " !\n";
        std::cerr << "In Function: " << error_function << ".\n";
    }

}
