#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        bool _guard;
        static const int _guardMp = 25;
    public:
        ScavTrap();
        ScavTrap(const ScavTrap& st);
        ScavTrap& operator=(const ScavTrap& ct);
        ~ScavTrap();

        void attack(std::string const& target);
        void takeDamage(unsigned int amount);

        ScavTrap(std::string name);
        bool getGuard(void);
        void guardGate();
};

#endif