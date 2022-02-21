#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    private:
        bool _guard;
        static const int _guardMp = 25;
    public:
        ScavTrap();
        ScavTrap(const ScavTrap& st);
        ScavTrap& operator=(const ScavTrap& ct);
        ~ScavTrap();

        ScavTrap(std::string name);

        void attack(std::string const& target);
        void takeDamage(unsigned int amount);
        void guardGate();
        bool getGuard(void) const;

        void setGuard(bool a);
        void setAd();
        void setMp();
        void setHp();
};

#endif