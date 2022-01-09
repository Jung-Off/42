
#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

#define RED 	"\x1b[31m"
#define GREEN 	"\x1b[32m"
#define YELLOW 	"\x1b[33m"
#define BLUE 	"\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN	"\x1b[36m"
#define RESET 	"\x1b[0m"

class Weapon
{
    private:
        std::string _TypeName;

    public:
        const std::string& getType();
        void setType(std::string name);
        Weapon(std::string name);
        ~Weapon();
};

#endif