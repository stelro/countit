#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <string>
#include <map>

#include "../include/extensions_lib.h"
#include "../include/file_data_info.h"
#include "../include/opendir.h"
#include "../include/commentstrip.h"

using namespace std;

int main(int argc, char **argv)
{
    stel::DirTools file_tools;
    stel::ExtensionHelper ext_tools;

    //this instance will track all the information about the files
    stel::FileInfo *file_keeper;

    vector<string> dir_names;
    vector<vector<string>> file_names;
    map<string,stel::FileInfo> infomap;
    map<string,stel::FileInfo>::iterator map_it;

    //--------------------------------------
    //Start, Stop, clock_t variables, keep track the time
    //of the file counting proccess
    //--------------------------------------

    clock_t Start,Stop;
    double seconds;

    //--------------------------------------

    const string unknown_string("Unknown");
    size_t lines_count{0};
    size_t chars_count{0};
    size_t files_count{0};
    size_t same_files{0};
    size_t overall_lines{0};
    size_t blanklines_count{0};
    size_t single_comments{0};
    size_t multi_comments{0};
    size_t scanned_files{0};
    bool flag = false;
    // bool unique = false;
    // bool empty = false;
    bool comments_flag = false;
    string error_check("");

    //------------------------------------

    if (argc != 2) {
        cout << "Usage: directory name\n" << endl;
        exit(1);
    }

    //-----------------------------------
    //passed as 1st argument the given path from user
    //and pushes the subdirectories in dir_names vector
    //-----------------------------------

    file_tools.parseDirectory(argv[1], 0, dir_names);

    Start = clock();

    for (auto &i : dir_names) {
        //get the filenames with their paths of every
        //subdirectory
        file_names.push_back(file_tools.open_directories(i));
    }

    string tmp_line;

    for(auto &row : file_names) {
        for(auto &col : row) {

            //takes the file extension, and returns the full name of it
            //e.x '.rb' returns -> 'Ruby'

            error_check = ext_tools.find_extension(col);
            files_count++;

            //check if the file extension we get is unequal of Unknonw
            //if so, then open the file, otherwise ignore it

            if (error_check != unknown_string) {

                ifstream file_f(col);
                file_keeper = new stel::FileInfo;
                map_it = infomap.find(error_check);

                //-------------------------------------------------
                //We check if there is value arledy exsist with this key
                //if yes, then we copy all informations to this key
                //and keep both , old and new values
                //also we set flag bool variable to true, so we just put back
                //all informations and not to make a new insertion with the
                //same key
                //-------------------------------------------------

                if (map_it != infomap.end()) {
                    flag = true;
                    chars_count = map_it->second.get_chars();
                    lines_count = map_it->second.get_lines();
                    blanklines_count = map_it->second.get_blank_lines();
                    same_files = map_it->second.get_file_number();
                    single_comments = map_it->second.get_s_comments();
                    multi_comments = map_it->second.get_m_comments();
                    same_files++;
                }
                else
                    same_files++;

                scanned_files++;
                //set extension name in every object
                file_keeper->set_extension(error_check);
                //Do not ignore whice spaces
                file_f.unsetf(ios::skipws);

                comments_flag = false;

                while(getline(file_f, tmp_line)) {
                    lines_count++;

                    stel::CommentStrip::GetLines(tmp_line,single_comments,multi_comments, error_check,comments_flag);

                    if((tmp_line.empty()))
                        blanklines_count++;
                }

                file_keeper->set_chars(chars_count);
                file_keeper->set_lines(lines_count);
                file_keeper->set_file_number(same_files);
                file_keeper->set_blanks(blanklines_count);
                file_keeper->set_s_comments(single_comments);
                file_keeper->set_m_comments(multi_comments);

                if(flag) {
                    //overite the arledy exsisting data in the object

                    map_it->second.set_chars(chars_count);
                    map_it->second.set_lines(lines_count);
                    map_it->second.set_file_number(same_files);
                    map_it->second.set_blanks(blanklines_count);
                    map_it->second.set_s_comments(single_comments);
                    map_it->second.set_m_comments(multi_comments);

                    flag = false;

                    same_files = 0;
                }
                else {
                    //Insert new pair with unique value of string which contains
                    //the extension name, and object class with all information

                    infomap.insert(pair<string,stel::FileInfo>(error_check, *file_keeper));
                }

                //memory dealocation
                file_f.close();
                delete file_keeper;
            }

            //reset counters

            chars_count = 0;
            lines_count = 0;
            blanklines_count = 0;
            single_comments = 0;
            multi_comments = 0;

        }
    }

    Stop = clock();
    seconds = ((double)(Stop-Start) / CLOCKS_PER_SEC);

    cout << endl;
   cout << "countme" << endl;
   cout << setfill('-') << setw(80) << "-" << endl;
   cout << setfill(' ');
   cout << "Total Files   : " << files_count << endl;
   cout << "Files scaned  : " << scanned_files << endl;
   cout << "Files ignored : " << files_count - scanned_files << endl;
   //output the seconds with accuracy of 2 decimal places
   cout << "Scan time     : " << setprecision(1) << seconds << "s" << endl;
   cout << setfill('-') << setw(80) << "-" << endl;
   cout << setfill(' ');
   cout << endl;

   cout << "Language" << setw(20) << "Files" << setw(10) <<  "comments" << setw(15) << "blank lines" << setw(10) << "lines" << endl;
   cout << setfill('-') << setw(80) << "-" << endl;
   cout << setfill(' ');

   for(auto map_it : infomap ) {

       cout << setw(25) << left << map_it.first;
       cout << setw(10) << left <<  map_it.second.get_file_number();
       cout << setw(11) << left <<  map_it.second.get_overall_comments();
       cout << setw(13) << left <<  map_it.second.get_blank_lines();
       cout << setw(10) << left <<  map_it.second.get_pure_lines();
       cout << endl;

       overall_lines += map_it.second.get_pure_lines();


   }

   cout << setfill('-') << setw(80) << "-" << endl;
   cout << setfill(' ');
   cout << setw(59) << left << "Overall: " << overall_lines << endl;
   cout << endl;


}
