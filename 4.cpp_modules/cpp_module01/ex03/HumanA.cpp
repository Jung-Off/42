
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
    : _name(name), _weapon(weapon)  
    {
        std::cout << "HumanA [" << YELLOW <<_name << RESET << "] "
            << std::endl;
    }

HumanA::~HumanA()
{
    std::cout << "HumanA [" << YELLOW <<_name << RESET << "] dead" << std::endl;
}

void HumanA::attack()
{
    std::cout << "HumanA [" << YELLOW <<_name << RESET << "] "
     << "[" << RED << _weapon.getType() << RESET << "] attack" << std::endl;
}