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

    //------------------------------------------------------------
    /* this method searching for every subdirectories with recursive
     * way, and then push it into a vector */
    //------------------------------------------------------------

    void DirTools::parseDirectory(const std::string &reading_directory, const int level, std::vector<std::string> &tmp)
    {
        if ( DIR *dp = opendir(reading_directory.c_str())) {
            tmp.push_back(reading_directory);

            while (struct dirent *ep = readdir(dp))
                if (ep->d_type == DT_DIR && ep->d_name[0] != '.')
                    parseDirectory(reading_directory + "/" + ep->d_name, level + 1, tmp);
            closedir(dp);
        }
        else {
            std::cerr << "Couldn't open the directory " << reading_directory << std::endl;
        }
    }
}
