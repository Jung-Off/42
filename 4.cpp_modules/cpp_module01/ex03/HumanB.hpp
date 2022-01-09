
#ifndef HUMANB_HPP
# define HUMANB_HPP

#define RED 	"\x1b[31m"
#define GREEN 	"\x1b[32m"
#define YELLOW 	"\x1b[33m"
#define BLUE 	"\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN	"\x1b[36m"
#define RESET 	"\x1b[0m"

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string _name;
        Weapon*     _weapon;
        
    public:
        void attack();
        void setWeapon(Weapon &weapon); // 이렇게 하면 reference
        HumanB(std::string name);
        ~HumanB();
};

#endif