
#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon&      _weapon;
    
    public:
        void attack();
        HumanA(std::string name, Weapon& weapon);
        ~HumanA();
};

#endif