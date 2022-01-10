
#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <fstream>

#define RED 	"\x1b[31m"
#define GREEN 	"\x1b[32m"
#define YELLOW 	"\x1b[33m"
#define BLUE 	"\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN	"\x1b[36m"
#define RESET 	"\x1b[0m"

class Transform
{
    private:
        std::string _file;
        std::string _before;
        std::string _after;

    public:
        std::string get_file();
        std::string get_before();
        Transform(std::string file, std::string before, std::string after);
        ~Transform();
};

int err_check(int ac, char **av);

#endif