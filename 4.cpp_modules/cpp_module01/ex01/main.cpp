
#include "Zombie.hpp"

int main()
{
    Zombie* zom;
    zom = zombieHorde(ZOMBIENUM, "abc");

    for (int i = 0; i < ZOMBIENUM; i++)
        zom[i].announce();

    delete[] zom; //살짝 * -> [] 해제
}