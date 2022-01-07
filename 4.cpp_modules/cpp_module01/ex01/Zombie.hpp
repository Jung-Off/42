#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#define RED 	"\x1b[31m"
#define GREEN 	"\x1b[32m"
#define YELLOW 	"\x1b[33m"
#define BLUE 	"\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN	"\x1b[36m"
#define RESET 	"\x1b[0m"

#define ZOMBIENUM 6

#include <iostream>
#include <sstream>

class Zombie
{
    private:
        std::string _name;
    public:
        void announce();
        void set_name(std::string name);
        std::string get_name();
        Zombie();
        Zombie(std::string name);
        
        ~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif