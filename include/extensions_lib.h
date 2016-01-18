#ifndef GUARD_EXTENSIONS_H
#define GUARD_EXTENSIONS_H

#include <iostream>
#include <map>

namespace ste {

    class ExtensionHelper {
    private:
        /* extension map, used to keep the files extensions e.x [.ext] as keys, and
        full-names file extension as values */
        std::map<std::string,std::string> extension_map;
        std::map<std::string,std::string>::iterator extension_map_iterator;
    public:
        /* documentation about those 2 methods are located in their
            definitions */
        std::string extension_to_name(const char *file_extension);
        std::string find_extension(const std::string file_name);
    };
    
}

#endif
