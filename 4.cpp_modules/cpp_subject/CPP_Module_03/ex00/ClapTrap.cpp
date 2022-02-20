
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    :   _name("NONAME"), _hitPoints(10), _energyPoint(10), _attackDamage(0), _maxHit(50)
{
    std::cout << "Constructor [" << BLUE << _name << RESET << "] ClapTrap " << std::endl;   
}

ClapTrap::ClapTrap(std::string name)
    :   _name(name), _hitPoints(10), _energyPoint(10), _attackDamage(0), _maxHit(50)
{
    std::cout << "Constructor [" << BLUE << _name  << RESET << "] ClapTrap " << std::endl;   
}

ClapTrap::ClapTrap(const ClapTrap& a)
    : _name(a.getName()), _hitPoints(a.getHit()), _energyPoint(a.getEnergy()), _attackDamage(a.getDamage()), _maxHit(50)
{
    std::cout << "Copy Constructor [" << BLUE << _name << RESET << "] ClapTrap " << std::endl;   
}

ClapTrap& ClapTrap::operator=(const ClapTrap& a)
{
    if(this == &a)
        return (*this);
    _name = a.getName();
    _hitPoints = a.getHit();
    _energyPoint = a.getEnergy();
    _attackDamage = a.getDamage();

    std::cout << "Operator = [" << CYAN << _name << RESET << "] ClapTrap " << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor ClapTrap " << _name << std::endl;   
}

//들어오는 상대방의 체력은 안까이나요? >> 여긴 그냥 단순 표현!
void ClapTrap::attack(std::string const& target)
{
    std::cout << "ClapTrap [" << RED << _name << RESET << "] attack "  << target <<
    ", causing [" << RED << _attackDamage << RESET << "] points of damage!" << std::endl;
}

//대미지를 받을때 0이하이거나 최대체력을 설정한다!?
void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << YELLOW << _name << RESET << " is Dead..." << std::endl;
        std::cout << "Now " << _name << "[" << RED << _hitPoints << RESET << "]" << std::endl << std::endl;
        return ;
    }
    if (_hitPoints > 0 && _hitPoints - amount <= 0)
    {
        std::cout << YELLOW << _name << RESET << "[" << RED << _hitPoints << RESET << "] Damaged..." << std::endl;
        _hitPoints  = 0;
    }
    else if (_hitPoints > 0 && _hitPoints - amount > 0)
    {
        std::cout << YELLOW << _name << RESET << "[" << RED << amount << RESET << "] Damaged..." << std::endl;
        _hitPoints -= amount;
    }
        std::cout << "Now " << _name << "[" << GREEN << _hitPoints << RESET << "]" << std::endl << std::endl;
}

//여기도 체력이 너무 많으면 회복이 안댐!
void ClapTrap::beRepaired(unsigned int mount)
{
    if (_hitPoints == _maxHit)
    {
        std::cout << "[" << MAGENTA << _name << RESET << "]" << "Full Enough Hit!" << std::endl;
    }
    else if (_hitPoints + mount > _maxHit)
    {
        std::cout << "[" << MAGENTA << _maxHit - _hitPoints << RESET << "] healing" << std::endl;
        _hitPoints = _maxHit;
    }
    else
    {
        std::cout << "[" << MAGENTA << mount << RESET << "] healing" << std::endl;
        _hitPoints += mount;
    }
    std::cout << "Now " << _name << "[" << GREEN << _hitPoints << RESET << "]" << std::endl << std::endl;
}

unsigned int ClapTrap::getDamage() const
{
    return(_attackDamage);
}

unsigned int ClapTrap::getEnergy() const
{
    return(_energyPoint);
}

unsigned int ClapTrap::getHit() const
{
    return(_hitPoints);
}

// unsigned int ClapTrap::getMHit() const
// {
//     return (_maxHit);
// }

std::string ClapTrap::getName() const
{
    return(_name);
}
