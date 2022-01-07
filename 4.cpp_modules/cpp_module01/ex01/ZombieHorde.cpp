#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie* zombieH = new Zombie[N];

    for (int i = 0; i < N; ++i)
    {
        std::stringstream its;
        its << i;
        zombieH[i].set_name(name + its.str());
    }
    return (zombieH);
}
