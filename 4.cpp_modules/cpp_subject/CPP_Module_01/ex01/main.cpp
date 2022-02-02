
#include "Zombie.hpp"

int main()
{
    Zombie *horde = zombieHorde(NUM, "Zombie");

    for (int i = 0; i < NUM; ++i)
        horde[i].Announce();
    delete []horde;
}