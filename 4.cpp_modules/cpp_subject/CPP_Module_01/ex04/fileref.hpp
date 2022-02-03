#ifndef FILEREF_HPP
# define FILEREF_HPP

#include "data.hpp"
#include <fstream>

#define RED 	"\x1b[31m"
#define GREEN 	"\x1b[32m"
#define YELLOW 	"\x1b[33m"
#define BLUE 	"\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN	"\x1b[36m"
#define RESET 	"\x1b[0m"

class File
{
    private:
        const Data& _data;
        std::ifstream _readFile;
        std::string _writeFileName;
        std::ofstream _writeFile;
    public:
        File(Data& data, std::string str);
        bool ReadOpen();
        bool WriteOpen();
        void Close();
        void Change();
        ~File();

};

#endif