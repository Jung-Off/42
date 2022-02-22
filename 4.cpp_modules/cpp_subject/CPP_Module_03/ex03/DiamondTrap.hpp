
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

//orthodox 규칙 맞추기!
//default constructor
//copy contructor
//assignation operator overload
//destructor.


class  DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string _name;
    public:
        DiamondTrap();
        DiamondTrap(const DiamondTrap& ft);
        DiamondTrap& operator=(const DiamondTrap& ft);
        ~DiamondTrap();
        DiamondTrap(std::string name);

        void attack(std::string const & target);
        void takeDamage(unsigned int amount);

        std::string getDName() const;
        std::string getName() const;
        unsigned int getHp() const;
        unsigned int getMp() const;
        unsigned int getAd() const;

        void whoAmI() const;
};

#endif