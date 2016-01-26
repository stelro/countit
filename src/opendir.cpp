#include "../include/opendir.h"

namespace stel {

    //FIXME: return reference vector
    std::vector<std::string> DirTools::open_directories(const std::string &path_dir)
    {
        DIR *directory;
        dirent *pdir;
        std::vector<std::string> files_names;
        directory = opendir(path_dir.c_str());
        std::string special("");

        while ((pdir = readdir(directory))) {
            //--------------------
            //ignore folders
            //--------------------

            if (!strcmp(pdir->d_name, ".") || !strcmp(pdir->d_name, ".."))
                continue;
            // return's the full path
            special = path_dir + '/' + pdir->d_name;
            files_names.push_back(special);

        }

        closedir(directory);

        return files_names;
    }
}
