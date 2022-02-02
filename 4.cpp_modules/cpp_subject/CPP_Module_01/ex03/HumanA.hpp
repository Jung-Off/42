#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        Weapon &_weapon;
        std::string _name;
    public:
        // HumanA(Weapon& weapon);
        HumanA(std::string name, Weapon& weapon);
        void attack() const;
        ~HumanA();
};

#endif