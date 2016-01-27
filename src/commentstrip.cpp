#include "../include/commentstrip.h"

namespace stel {

    void CommentStrip::GetLines(const std::string &line, size_t &single_comm, size_t &multi_comm, const std::string &language, bool &flag)
    {
        if (language == "C" || language == "C++") {

            std::regex single_regex("(//.*)");
            std::regex multi_regex("/\\*.*?");
            std::regex multi_close_regex("\\*/");

            std::string tmp_line;

            if (!line.empty()) {
                if (std::regex_search(line,single_regex))
                    single_comm++;
                if(std::regex_search(line,multi_regex))
                    flag = true;
                if(flag)
                    multi_comm++;
                if(std::regex_search(line, multi_close_regex) && flag == true)
                    flag = false;
            }

        }
    }
}
