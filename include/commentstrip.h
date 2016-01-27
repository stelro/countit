#ifndef GUARD_COMMENTSTRIP_H
#define GUARD_COMMENTSTRIP_H

#include <iostream>
#include <regex>

namespace stel {
class CommentStrip {
    private:
    size_t single_comments;
    size_t multi_comments;
    public:
        CommentStrip();
    public:
        void GetLines(const std::string &line, size_t &single_comm, size_t &multi_comm, const std::string &language);

    };
}

#endif
