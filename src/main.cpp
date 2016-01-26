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

using namespace std;

int main(int argc, char **argv)
{
    stel::DirTools file_tools;
    stel::ExtensionHelper ext_tools;

    //this instance will track all the information about the files
    stel::FileInfo *file_keeper;

    vector<string> dir_names;
    vector<vector<string>> file_names;
    //FIXME: const_iterator
    vector<vector<string>>::iterator row;
    vector<string>::iterator col;

}
