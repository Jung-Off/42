
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    :   ClapTrap("NoName_clap_name")
{
    _name = "NoName";
    FragTrap::setHp();
    ScavTrap::setMp();
    FragTrap::setAd();
    _guard = false;
    std::cout << "Constructor [" << YELLOW << getDName() << RESET << "]" << BMAGENTA << "DiamondTrap " << RESET << std::endl;   
}

DiamondTrap::DiamondTrap(std::string name)
    :   ClapTrap(name + "_clap_name")
{
    _name = name;
    FragTrap::setHp();
    ScavTrap::setMp();
    FragTrap::setAd();
    _guard = false;

    std::cout << "Constructor [" << YELLOW << getDName() << RESET << "] " << BMAGENTA << "DiamondTrap " << RESET << std::endl;   
}

DiamondTrap::DiamondTrap(const DiamondTrap& ft) : ScavTrap(ft.getName())
{
    _name = ft.getDName();
    _hp = ft.getHp();
    _mp = ft.getMp();
    _ad = ft.getAd();
    _guard = getGuard();
    std::cout << "Copy Constructor [" << YELLOW << getDName() << RESET << "] " << BMAGENTA << "DiamondTrap " << RESET << std::endl;   
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& ft)
{
    if (this == &ft)
        return (*this);
    // ClapTrap::operator=(ft);
    ScavTrap::_name = ft.getName();
    _hp = ft.getHp();
    _mp = ft.getMp();
    _ad = ft.getAd();
    _name = ft.getDName();
    _guard = getGuard();
    std::cout << "Operator = [" << YELLOW << getDName() << RESET << "] " << BMAGENTA << "DiamondTrap " << RESET << std::endl;
    return (*this);
}

void DiamondTrap::attack(std::string const & target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount)
{
    std::cout << BMAGENTA << "DiamondTrap " << RESET;
    if (_guard)
    {
        std::cout << "No Damaged !" << std::endl;
        _guard = false;
    }
    else
        ClapTrap::takeDamage(amount);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Destructor " << "[" << YELLOW << getDName() << RESET << "]" << BMAGENTA << "DiamondTrap " << RESET  << std::endl;   
}

std::string DiamondTrap::getName() const
{
    return (ClapTrap::getName());
}

unsigned int DiamondTrap::getHp() const
{
    return (ClapTrap::getHp());
}

unsigned int DiamondTrap::getMp() const
{
    return (ClapTrap::getMp());
}

unsigned int DiamondTrap::getAd() const
{
    return (ClapTrap::getAd());
}

std::string DiamondTrap::getDName() const
{
    return (_name);
}

void DiamondTrap::whoAmI() const
{
    std::cout << "DiamondTrap : [" << YELLOW << getDName() << RESET << "] ClapTrap : [" << YELLOW << getName() << RESET << "]" << std::endl;
}