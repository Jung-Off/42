#include "HumanB.hpp"

HumanB::HumanB(std::string name)
    : _name(name)  
    {
        std::cout << "HumanB [" << BLUE <<_name << RESET << "] "
            << std::endl;
    }

HumanB::~HumanB()
{
    std::cout << "HumanB [" << BLUE <<_name << RESET << "] dead" << std::endl;
}

void HumanB::attack()
{
    std::cout << "HumanB [" << BLUE <<_name << RESET << "] "
     << "[" << RED << _weapon->getType() << RESET << "] attack" << std::endl;
}


void HumanB::setWeapon(Weapon& weapon) //Weapon weapon _weapon = &weapon 하면 주소가 복사가 안되나?
{
    _weapon = &weapon; //reference의 주소
}