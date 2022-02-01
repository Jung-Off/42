#include "Zombie.hpp"

Zombie::Zombie()
    :   _name("NoName")
{
    std::cout << BLUE << _name << RESET << " Made !" << std::endl;
}

Zombie::Zombie(std::string name)
    : _name(name)
{
    std::cout << RED << _name << RESET << " Made !" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << _name << BLUE << " D" << RED << "e" <<
    BLUE << "a" << RED << "d" << RESET << "..." << std::endl;
}

void Zombie::Announce()
{
    std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}