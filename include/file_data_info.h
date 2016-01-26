#ifndef GUARD_FILE_DATA_INFO
#define GUARD_FILE_DATA_INFO

#include "extensions_lib.h"

namespace stel {

    /* this class , track information about every unique file */
    //TODO: maybe additon operator overloading
    class FileInfo : public ExtensionHelper {
    private:
        size_t chars_counter;
        size_t lines_counter;
        size_t blank_counter;
        size_t single_comments_counter;
        size_t multi_comments_counter;
        size_t file_number;
        bool unique;
        bool empty;
        std::string file_extension;
    public:
        FileInfo();
        FileInfo(const FileInfo &copy_file);
        FileInfo(const size_t chars, const size_t lines, const size_t blank, const size_t s_comments, const size_t m_comments,
                const size_t file, const bool uni, const bool empt, const std::string &ext);
        //constructor if file is empty set all to 0 and stop scaning file
        FileInfo(const bool emp);
        void set_chars(const size_t chars) { chars_counter = chars; }
        void set_lines(const size_t lines) { lines_counter = lines; }
        void set_file_number(const size_t file_no) { file_number = file_no; }
        void set_extension(const std::string &ext) { file_extension = ext; }
        void set_blanks(const size_t blank) { blank_counter = blank; }
        void set_s_comments(const size_t s_comments) { single_comments_counter = s_comments; }
        void set_m_comments(const size_t m_comments) { multi_comments_counter = m_comments; }
        size_t get_chars() const { return chars_counter; }
        size_t get_lines() const { return lines_counter; }
        size_t get_blank_lines() const { return blank_counter; }
        size_t get_s_comments() const { return single_comments_counter; }
        size_t get_m_comments() const { return multi_comments_counter; }
        size_t get_file_number() const { return file_number; }
        bool is_unique() const { return unique; }
        bool is_empty() const { return empty; }
        std::string get_file_extension() const { return file_extension; }

    };
}

#endif
