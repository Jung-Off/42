#include "Zombie.hpp"

//heap
Zombie*     newZombie( std::string name )
{
    Zombie* nZombie = new Zombie(name);
    std::cout << YELLOW << "[" << name << "]" << RESET 
    << " is create by NEW" << "(Dynamic memory allocation)" << std::endl; 
    return (nZombie);
}