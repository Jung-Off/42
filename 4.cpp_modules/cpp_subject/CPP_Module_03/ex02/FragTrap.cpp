
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    setAd(30);
    setHp(100);
    setMp(100);

    std::cout << "Constructor [" << YELLOW << getName() << RESET << "] " << BBLUE << "FragTrap " << RESET << std::endl;   
}

FragTrap::FragTrap(const FragTrap& ft)
    : ClapTrap(ft.getName())
{
    _hp = ft.getHp();
    _mp = ft.getMp();
    _ad = ft.getAd();

    std::cout << "Copy Constructor [" << YELLOW << getName() << RESET << "] " << BBLUE << "FragTrap " << RESET << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap& ft)
{
    if (this == &ft)
        return (*this);

    _name = ft.getName();
    _hp = ft.getHp();
    _mp = ft.getMp();
    _ad = ft.getAd();

    std::cout << "Operator = [" << YELLOW << getName() << RESET << "] " << BBLUE << "FragTrap " << RESET << std::endl;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor "<< YELLOW << "[" << getName() << "] " << RESET << BBLUE << "FragTrap" << RESET << std::endl;   
}

FragTrap::FragTrap(std::string name)
    : ClapTrap(name)
{
    setAd(30);
    setHp(100);
    setMp(100);

    std::cout << "Constructor [" << YELLOW << getName() << RESET << "] " << BBLUE << "FragTrap " << RESET << std::endl;   
}

void FragTrap::attack(std::string const& target)
{
    std::cout << MAGENTA << "ATTACK  >> " <<  RESET; 
    std::cout << BBLUE << "FragTrap" << RESET << "[" << YELLOW << _name << RESET << "] attack "  << target <<
    ", causing [" << RED << _ad << RESET << "] points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
    std::cout << BBLUE << "FragTrap " << RESET;
    ClapTrap::takeDamage(amount);
}

void FragTrap::highFivesGuys(void) const
{
    std::cout << "[" << YELLOW << _name << RESET << "]" << " feel good" <<
    " I feel strong" << std::endl;
}