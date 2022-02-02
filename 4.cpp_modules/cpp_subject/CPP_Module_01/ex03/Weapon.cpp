#include "Weapon.hpp"

// Weapon::Weapon()
//     : _type("NoType")
// {
//     std::cout << _type << " made" << std::endl;
// }

Weapon::Weapon(std::string type)
    : _type(type)
{
    std::cout << "[" <<_type << "]" << " made" << std::endl;
}

const std::string& Weapon::getType()
{
    return(_type);
}

void Weapon::setType(std::string type)
{
    std::cout << "[" << RED << _type << RESET << "] -> " << "[" 
    << BLUE << type << RESET << "]" << std::endl;
    _type = type;
}

Weapon::~Weapon()
{
    std::cout << "[" << _type << "]" << " Break.." << std::endl << std::endl;
}