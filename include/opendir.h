#ifndef GUARD_OPENDIR_H
#define GUARD_OPENDIR_H

#include <iostream>
#include <vector>
#include <dirent.h>
#include <cstring>
#include "error_handling.h"

namespace stel {
    class DirTools {
    public:
        std::vector<std::string> open_directories(const std::string &path_dir);
        static void parseDirectory(const std::string &reading_directory, const int level, std::vector<std::string> &tmp);
    };
}

#endif
