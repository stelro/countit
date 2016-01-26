#include "../include/file_data_info.h"

namespace stel {

    FileInfo::FileInfo() :
        chars_counter(0),lines_counter(0),blank_counter(0),single_comments_counter(0),multi_comments_counter(0),file_number(0),unique(false),empty(false),file_extension("")
        { }

    //copy constructor
    FileInfo::FileInfo(const FileInfo &copy_file)
    {
        if(this != &copy_file) {
            chars_counter = copy_file.chars_counter;
            lines_counter = copy_file.lines_counter;
            blank_counter = copy_file.blank_counter;
            single_comments_counter = copy_file.single_comments_counter;
            multi_comments_counter = copy_file.multi_comments_counter;
            file_number = copy_file.file_number;
            unique = copy_file.unique;
            empty = copy_file.empty;
            file_extension = copy_file.file_extension;
        }
    }

    FileInfo::FileInfo(const size_t chars, const size_t lines, const size_t blank, const size_t s_comments, const size_t m_comments,
            const size_t file, const bool uni, const bool empt, const std::string &ext) :
                chars_counter(chars),lines_counter(lines),blank_counter(blank),single_comments_counter(s_comments),multi_comments_counter(m_comments),file_number(file),
                unique(uni),empty(empt),file_extension(ext)
                { }

    FileInfo::FileInfo(const bool emp) :
        chars_counter(0),lines_counter(0),blank_counter(0),single_comments_counter(0),multi_comments_counter(0),file_number(0),unique(false),empty(emp),file_extension("")
        { }


}
