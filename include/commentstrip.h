#ifndef GUARD_COMMENTSTRIP_H
#define GUARD_COMMENTSTRIP_H

#include <iostream>
#include <string>
#include <regex>

namespace stel {
class CommentStrip {
    public:
        static void GetLines(const std::string &line, size_t &single_comm, size_t &multi_comm, const std::string &language, bool &flag);

    };
}

#endif
