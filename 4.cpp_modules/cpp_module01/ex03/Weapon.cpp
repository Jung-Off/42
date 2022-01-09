
#include "Weapon.hpp"

const std::string& Weapon::getType()
{
    return (_TypeName);
}

void Weapon::setType(std::string name)
{
    std::cout << "Change my Weapon " << "[" << RED << _TypeName << RESET << "]"
    << " --> " << "[" << RED << name << RESET << "]" << std::endl;
    _TypeName = name;

}

Weapon::Weapon(std::string name)
    : _TypeName(name)
{
    std::cout << "[" << RED << _TypeName << RESET << "]" << " Made Weapon" << std::endl;
}

Weapon::~Weapon()
{
     std::cout << "[" << RED << _TypeName << RESET << "]" 
        << " Delete Weapon" << std::endl;
}