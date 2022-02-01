#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie* random = newZombie(name);
    random->Announce();
    std::cout << "randomChump Delete" << std::endl;
    delete random;
}