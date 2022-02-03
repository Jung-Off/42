
#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

#define RED 	"\x1b[31m"
#define GREEN 	"\x1b[32m"
#define YELLOW 	"\x1b[33m"
#define BLUE 	"\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN	"\x1b[36m"
#define RESET 	"\x1b[0m"

class Data
{
    private:
        std::string _FileName;
        std::string _Before;
        std::string _After;
    public:
        std::string getFilename() const;
        std::string getBefore() const;
        std::string getAfter() const;
        Data(std::string file, std::string before, std::string after);
        ~Data();
};


#endif