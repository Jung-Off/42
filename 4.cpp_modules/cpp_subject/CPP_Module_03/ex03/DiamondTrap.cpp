
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    :   ClapTrap("NoName_clap_name")
{
    _hp = FragTrap::getHp();
    _mp = ScavTrap::getMp();
    _ad = FragTrap::getAd();

    std::cout << "Constructor [" << BLUE << getName() << RESET << "] DiamondTrap " << std::endl;   
}

DiamondTrap::DiamondTrap(std::string name)
    :   ClapTrap(name + "_clap_name")
{
    _hp = FragTrap::getHp();
    _mp = ScavTrap::getMp();
    _ad = FragTrap::getAd();

    std::cout << "Constructor [" << BLUE << getName() << RESET << "] DiamondTrap " << std::endl;   
}

DiamondTrap::DiamondTrap(const DiamondTrap& ft)
{
    _hp = FragTrap::getHp();
    _mp = ScavTrap::getMp();
    _ad = FragTrap::getAd();
    _name = ClapTrap::getName();
    std::cout << "Copy Constructor [" << BLUE << getName() << RESET << "] DiamondTrap " << std::endl;   
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& ft)
{
    if (this == &ft)
        return (*this);
    _hp = FragTrap::getHp();
    _mp = ScavTrap::getMp();
    _ad = FragTrap::getAd();
    _name = ClapTrap::getName();
    std::cout << "Operator = [" << CYAN << getName() << RESET << "] DiamondTrap " << std::endl;
    return (*this);
}

void DiamondTrap::attack(std::string const & target)
{
     ScavTrap::attack();
}

void DiamondTrap::takeDamage(unsigned int amount)
{
    FragTrap::takeDamage(amount);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Destructor DiamondTrap " << getName() << std::endl;   
}
