#include "HumanA.hpp"

// HumanA::HumanA(Weapon& weapon)
//     : _weapon(weapon), _name("NoName")
// {
//     std::cout << "name : " << _name <<
//     " weaponType : " << _weapon.getType() << std::endl << std::endl;
// }

HumanA::HumanA(std::string name, Weapon& weapon)
    : _weapon(weapon), _name(name)
{
    std::cout << "name " << "[" << _name << "]" <<
    " weaponType " << "[" << _weapon.getType() << "]" << std::endl << std::endl;
}

void HumanA::attack() const
{
    std::cout << "[" << _name <<  "]" << " attacks with his " <<
        "[" << _weapon.getType() << "]" << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "HumanA " << "[" << _name << "]" << " died.." 
        << "[" << _weapon.getType() << "]" << std::endl;
}