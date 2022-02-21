
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    setAd();
    setHp();
    setMp();

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
    setAd();
    setHp();
    setMp();

    std::cout << "Constructor [" << BLUE << getName() << RESET << "] FragTrap " << std::endl;   
}

void FragTrap::attack(std::string const& target)
{
    std::cout << "FragTrap [" << RED << _name << RESET << "] attack "  << target <<
    ", causing [" << RED << _ad << RESET << "] points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
    std::cout << "FragTrap attack!  ";
    ClapTrap::takeDamage(amount);
}

void FragTrap::highFivesGuys(void) const
{
    std::cout << "[" << _name << "]" << " feel good" <<
    " I feel strong" << std::endl;
}

void FragTrap::setAd()
{
    ClapTrap::setAd(30);
}

void FragTrap::setMp()
{
    ClapTrap::setMp(100);
}

void FragTrap::setHp()
{
    ClapTrap::setHp(100);
}