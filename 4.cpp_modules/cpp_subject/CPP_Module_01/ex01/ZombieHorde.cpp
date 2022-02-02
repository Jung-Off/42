#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *Horde = new Zombie[N];

    for (int i = 0; i < N; ++i)
    {
        std::stringstream NameAdd;
        NameAdd << i + 1;
        Horde[i].SetName(name + NameAdd.str());
    }
    return (Horde);
}