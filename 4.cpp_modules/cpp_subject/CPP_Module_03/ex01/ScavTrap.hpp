#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        bool _guard;
        static const int _guardEnergy = 25;
    public:
    //생성자, 소멸자 및 공격
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap& operator=(const ScavTrap& a);
    void attack(std::string const& target);
    void takeDamage(unsigned int amount);
    ~ScavTrap();
    void guardGate();
};

#endif