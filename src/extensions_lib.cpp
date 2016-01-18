#include "../include/extensions_lib.h"

namespace ste {

    std::string ExtensionHelper::find_extension(const std::string file_name)
    {
        /* this function gets the full file name with the extension
            and keeps only the part after the dot, namely, the extension
            eg , somefile.cpp will become [cpp] */

        std::string extension = "";
        size_t pos = file_name.find_last_of(".");
        extension = file_name.substr(pos+1);

        /* returns the full name of the programming language, for e.x ["C++"]
        instead of just the extension, the method extension_to_name, converts
        the extension to full language name! */

        //c_str() is used because extension_to_name function expects to get char pointer insted of string

        return this->extension_to_name(extension.c_str());
    }

    std::string ExtensionHelper::extension_to_name(const char *file_extension)
    {

        const std::string unknown_extension = "Unknown";

        extension_map["c"] = "C";
    	extension_map["h"] = "C/C++ Header";
    	extension_map["cc"] = "C++";
    	extension_map["cpp"] = "C++";
    	extension_map["cxx"] = "C++";
    	extension_map["c++"] = "C++";
    	extension_map["rb"] = "Ruby";
    	extension_map["rbw"] = "Ruby";
    	extension_map["py"] = "Python";
    	extension_map["pyc"] = "Python";
    	extension_map["pyd"] = "Python";
    	extension_map["pyo"] = "Python";
    	extension_map["pyw"] = "Python";
    	extension_map["pyz"] = "Python";
    	extension_map["java"] = "Java";
    	extension_map["class"] = "Java";
    	extension_map["jar"] = "Java";
    	extension_map["cs"] = "C#";
    	extension_map["js"] = "Javascript";
    	extension_map["html"] = "Html";
    	extension_map["html"] = "Html";
    	extension_map["css"] = "CSS";
    	extension_map["coffee"] = "Coffescript";
    	extension_map["ts"] = "Typescript";
    	extension_map["pl"] = "Perl";
    	extension_map["pm"] = "Perl";
    	extension_map["t"] = "Perl";
    	extension_map["pod"] = "Perl";
    	extension_map["sh"] = "Bash";
    	extension_map["sass"] = "SASS";
    	extension_map["scss"] = "SASS";
    	extension_map["less"] = "LESS";
    	extension_map["lisp"] = "LISP";
    	extension_map["cl"] = "LISP";
        extension_map["lsp"] = "LISP";
    	extension_map["hs"] = "Haskell";
    	extension_map["lsh"] = "Haskell";
    	extension_map["scala"] = "Scala";
    	extension_map["rs"] = "Rust";
    	extension_map["rlib"] = "Rust";
    	extension_map["go"] = "Go Lang";
        extension_map["ada"] = "Ada";
        extension_map["adb"] = "Ada";
        extension_map["ads"] = "Ada";
        extension_map["am"] = "Make";
        extension_map["as"] = "ActionScript";
        extension_map["asa"] = "ASP";
        extension_map["asax"] = "ASP.net";
        extension_map["asac"] = "ASP.net";
        extension_map["asmx"] = "ASP.net";
        extension_map["asp"] = "ASP";
        extension_map["master"] = "ASP.net";
        extension_map["sitemap"] = "ASP.net";
        extension_map["asm"] = "Assembly";
        extension_map["s"] = "Assembly";
        extension_map["awk"] = "Awk";
        extension_map["php"] = "PHP";
        extension_map["php3"] = "PHP";
        extension_map["php4"] = "PHP";
        extension_map["php5"] = "PHP";
        extension_map["pas"] = "Pascal";
        extension_map["p"] = "Pascal";
        extension_map["pp"] = "Pascal";
        extension_map["sql"] = "SQL";
        extension_map["vb"] = "Visual Basic";
        extension_map["vbs"] = "Visual Basic";
        extension_map["vba"] = "Visual Basic";
        extension_map["frm"] = "Visual Basic";
        extension_map["xaml"] = "Xaml";
        extension_map["vim"] = "Vim script";
        extension_map["vhd"] = "VHDL";
        extension_map["vhdl"] = "VHDL";
        extension_map["m"] = "Matlab/Objective C";
        extension_map["mm"] = "Objective C";
        extension_map["f77"] = "Fortran 77";
        extension_map["f90"] = "Fortran 90";
        extension_map["f95"] = "Fortran 95";
        extension_map["f"] = "Fortran 77";
        extension_map["dart"] = "Dart";
        extension_map["d"] = "D";
        extension_map["csh"] = "C Shell";
        extension_map["json"] = "JSON";
        extension_map["elr"] = "Erlang";
        extension_map["bat"] = "DOS Batch";
        extension_map["yml"] = "YAML";
        extension_map["yaml"] = "YAML";
        extension_map["lua"] = "Lua";
        extension_map["mg"] = "Modula3";
        extension_map["m3"] = "Modula3";

        /* finds an element with key equivalent to key!
        complexity, logarithmic in the size of the container ( log(N) ) */

        /* if no key found, return unknown extension */

        extension_map_iterator = extension_map.find(file_extension);
        if(extension_map_iterator != extension_map.end())
            return extension_map_iterator->second;
        else
            return unknown_extension;
    }

}
