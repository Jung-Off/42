#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie* Zombie = newZombie(name);
    Zombie->announce();

    delete Zombie;
    Zombie = NULL;
}