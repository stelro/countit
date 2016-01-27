#include "../include/commentstrip.h"

namespace stel {
    CommentStrip::CommentStrip() :
        single_comments(0), multi_comments(0) { }
        
    void CommentStrip::GetLines(const std::string &line, size_t &single_comm, size_t &multi_comm, const std::string &language)
    {
        if (language == "C" || language == "C++") {

            std::regex single_regex("(//.*)");
            std::regex multi_regex("/\\*.*?");
            std::regex multi_close_regex("\\*/");

            std::string tmp_line;

            single_comments = 0;
            multi_comments = 0;

            bool flag = false;

            while(!line.empty()) {
                if (std::regex_search(line,single_regex))
                    single_comments++;
                if(std::regex_search(line,multi_regex))
                    flag = true;
                if(flag)
                    multi_comments++;
                if(std::regex_search(line, multi_close_regex) && flag == true)
                    flag = false;
            }

            single_comm = single_comments;
            multi_comm = multi_comments;

        }
    }
}
