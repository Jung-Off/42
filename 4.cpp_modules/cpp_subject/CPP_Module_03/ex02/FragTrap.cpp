
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    setAd(30);
    setHp(100);
    setMp(100);

    std::cout << "Constructor [" << BLUE << getName() << RESET << "] FragTrap " << std::endl;   
}

FragTrap::FragTrap(const FragTrap& ft)
    : ClapTrap(ft.getName())
{
    _hp = ft.getHp();
    _mp = ft.getMp();
    _ad = ft.getAd();

    std::cout << "Copy Constructor [" << BLUE << getName() << RESET << "] FragTrap " << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap& ft)
{
    if (this == &ft)
        return (*this);

    _name = ft.getName();
    _hp = ft.getHp();
    _mp = ft.getMp();
    _ad = ft.getAd();

    std::cout << "Operator = [" << CYAN << getName() << RESET << "] ScavTrap " << std::endl;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor FragTrap " << getName() << std::endl;   
}

FragTrap::FragTrap(std::string name)
    : ClapTrap(name)
{
    setAd(30);
    setHp(100);
    setMp(100);

    std::cout << "Constructor [" << BLUE << getName() << RESET << "] FragTrap " << std::endl;   
}

void FragTrap::highFivesGuys(void) const
{
    std::cout << "[" << _name << "]" << " feel good" <<
    " I feel strong" << std::endl;
}