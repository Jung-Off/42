#include "HumanB.hpp"

// HumanB::HumanB()
//     : _weapon(NULL), _name("NoName")
// {

// }

HumanB::HumanB(std::string name)
    : _weapon(NULL), _name(name)
{
    std::cout << "name " << "[" << _name << "]" <<
    " weaponType : (NULL)" << std::endl << std::endl;
}

// HumanB::HumanB(Weapon *weapon)
//     : _name("NoName")
// {
//     weapon = new Weapon("Sword");
// }

// HumanB::HumanB(Weapon *weapon, std::string name)
//     : _name(name)
// {
//     weapon = new Weapon("SwordMaster");
// }

void HumanB::setWeapon(Weapon& club)
{
    _weapon = &club;
}

void HumanB::attack() const
{
    if (_weapon == NULL)
    {
        std::cout << "not have anything" << std::endl;
        return ;
    }
    std::cout << "[" << _name << "]" << " attacks with his " <<
        "[" << _weapon->getType() << "]" << std::endl;
    // else
    //     std::cout << "Weapon is NULL" << std::endl;
}

HumanB::~HumanB()
{
    // if (_weapon != NULL)
    //     delete _weapon;
    std::cout << "HumanB " << "[" << _name << "]" << " died.. ";
    if (_weapon != NULL)
        std::cout << "[" << _weapon->getType() << "]" << std::endl;
    else
        std::cout << " [ NULL ]" << std::endl;
}
