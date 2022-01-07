
#include "Zombie.hpp"

int main()
{
    std::cout << "Default Constructor Call(noname)" << std::endl;
    Zombie zombie1;             // RED default Constructor
    std::cout << RED << "[" << zombie1.get_name() << "]" << RESET 
            << " : Default Constructor NONAME" << std::endl;
    std::cout << std::endl;

    std::cout << "Default Constructor Call(name)" << std::endl;
    Zombie zombie2("zom");    // GREEN default Constructor
    std::cout << GREEN << "[" << zombie2.get_name() << "]" << RESET
            << " : Default Constructor NAME" << std::endl;
    std::cout << std::endl;

    std::cout << "=== new example ===" << std::endl;
    std::cout << "Create" << std::endl;
    Zombie* zombie_star = newZombie("new"); // YELLOW new create no crowd

    delete zombie_star;
    zombie_star = NULL;

    std::cout << std::endl;
    std::cout << "=== randomChump example === " << std::endl;
    std::cout << "Create + Announce" << std::endl;
    randomChump("Chump");            // CYAN  create yes crowd;



    // system("leaks Zombie");

}