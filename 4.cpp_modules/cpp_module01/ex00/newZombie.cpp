#include "Zombie.hpp"

//heap
Zombie*     newZombie( std::string name )
{
    Zombie* nZombie = new Zombie(name);
    std::cout << YELLOW << name << " create" << RESET << std::endl; 
    return (nZombie);
}