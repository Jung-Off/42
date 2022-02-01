
#include "Zombie.hpp"

int main()
{
    std::cout << "===== local =====" << std::endl;
    Zombie ZombieNoArg;
    Zombie ZombieArg("ARG");

    ZombieNoArg.Announce();
    ZombieArg.Announce();
    std::cout << "===== local =====" << std::endl << std::endl;;

    std::cout << "===== heap =====" << std::endl;
    Zombie *newZom = newZombie("NEW");
    newZom->Announce();
    std::cout << "newZom Delete" << std::endl; 
    delete newZom;
    std::cout << "===== heap =====" << std::endl << std::endl;

    std::cout << "===== random Chump =====" << std::endl;
    randomChump("Random");
    std::cout << "===== random Chump =====" << std::endl << std::endl;

}