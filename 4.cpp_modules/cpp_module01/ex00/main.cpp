
#include "Zombie.hpp"

int main()
{
    Zombie zombie1; // RED default Constructor
    Zombie zombie2("hello"); // GREEN default Constructor

    Zombie* zombie_star = newZombie("new"); // YELLOW new create no crowd

    randomChump("random_Chump"); //CYAN  create yes crowd;

    std::cout << RED << zombie1.get_name() << RESET << std::endl;
    std::cout << GREEN << zombie2.get_name() << RESET << std::endl;
    std::cout << YELLOW << zombie_star->get_name() << RESET << std::endl;

    delete zombie_star;
    zombie_star = NULL;

    system("leaks Zombie");

}