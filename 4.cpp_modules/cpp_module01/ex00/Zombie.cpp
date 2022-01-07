
#include "Zombie.hpp"

// RED default Constructor
Zombie::Zombie()
    : _name("NO_NAME")
    {}

// GREEN default Constructor
Zombie::Zombie(std::string name)
    : _name(name)
    {}

Zombie::~Zombie()
{
    std::cout << CYAN << "[" << get_name() << "]" << RESET << " : Default Destructor" << std::endl;
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
    std::cout << YELLOW << get_name() << RESET << " BraiiiiiiinnnzzzZ..." << std::endl;
}