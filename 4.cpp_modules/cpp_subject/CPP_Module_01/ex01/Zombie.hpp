
#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <sstream>

#define RED 	"\x1b[31m"
#define GREEN 	"\x1b[32m"
#define YELLOW 	"\x1b[33m"
#define BLUE 	"\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN	"\x1b[36m"
#define RESET 	"\x1b[0m"

#define NUM 6

class Zombie
{
    private :
        std::string _name;
    public :
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void Announce();
        void SetName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif