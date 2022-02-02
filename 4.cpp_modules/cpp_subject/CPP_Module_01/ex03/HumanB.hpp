#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    private:
        Weapon* _weapon;
        std::string _name;
    public:
        // HumanB();
        HumanB(std::string name);
        // HumanB(Weapon *weapon);
        // HumanB(Weapon *weapon, std::string name);
        void setWeapon(Weapon& club);
        void attack() const;
        ~HumanB();
};

#endif