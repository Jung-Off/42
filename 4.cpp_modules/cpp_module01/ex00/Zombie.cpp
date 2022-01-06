
#include "Zombie.hpp"

Zombie::Zombie()
    : _name("NO_NAME")
    {}

Zombie::Zombie(std::string name)
    : _name(name)
    {}

Zombie::~Zombie()
{
    std::cout << get_name() << " ZOMBIE_DEAD" << std::endl;
}

void Zombie::set_name(std::string name)
{
    _name = name;
}

std::string Zombie::get_name()
{
    return(_name);
}

void Zombie::announce()
{
    std::cout << get_name() << " BraiiiiiiinnnzzzZ..." << std::endl;
}