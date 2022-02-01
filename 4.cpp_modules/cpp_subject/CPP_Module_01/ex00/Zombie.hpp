
#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

#define RED 	"\x1b[31m"
#define GREEN 	"\x1b[32m"
#define YELLOW 	"\x1b[33m"
#define BLUE 	"\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN	"\x1b[36m"
#define RESET 	"\x1b[0m"

class Zombie
{
    private :
        std::string _name;
    public :
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void Announce();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif