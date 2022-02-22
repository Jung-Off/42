
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name("NONAME"), _hp(10), _mp(10), _ad(0)
{
    std::cout << "Constructor [" << YELLOW << _name << RESET << "] " << BRED << "ClapTrap " << RESET << std::endl;   
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hp(10), _mp(10), _ad(0)
{
    std::cout << "Constructor [" << YELLOW << _name << RESET << "] " << BRED << "ClapTrap " << RESET << std::endl;   
}

ClapTrap::ClapTrap(const ClapTrap& ct)
    : _name(ct.getName()), _hp(ct.getHp()), _mp(ct.getMp()), _ad(ct.getAd())
{
    std::cout << "Copy Constructor [" << YELLOW << _name << RESET << "] " << BRED << "ClapTrap " << RESET << std::endl;   
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ct)
{
    if (this == &ct)
        return (*this);
    _name = ct.getName();
    _hp = ct.getHp();
    _mp = ct.getMp();
    _ad = ct.getAd();

    std::cout << "Operator = [" << YELLOW << _name << RESET << "] " << BRED << "ClapTrap " << RESET << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor [" << YELLOW << _name << RESET << "] " << BRED << "ClapTrap " << RESET << std::endl;   
}

//들어오는 상대방의 체력은 안까이나요? >> 여긴 그냥 단순 표현!
void ClapTrap::attack(std::string const& target)
{
    std::cout << MAGENTA << "ATTACK  >> " <<  RESET; 
    std::cout << BRED << "ClapTrap " << RESET << "[" << YELLOW << _name << RESET << "] attack "  << target <<
    ", causing [" << RED << _ad << RESET << "] points of damage!" << std::endl;
}

//대미지를 받을때 0이하이거나 최대체력을 설정한다!?
void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << RED << "TAKE DAMAGE  >> " <<  RESET; 
    if (_hp == 0)
    {
        std::cout << YELLOW << _name << RESET << " is Dead... " << std::endl;
        return ;
    }
    if (_hp > 0 && _hp <= amount)
    {
        std::cout  << "[" << RED << _hp << RESET << "] Damaged... "
         << "Real Damage [" << RED << amount << RESET << "] ";
        _hp = 0;
    }
    else if (_hp > 0 && _hp > amount)
    {
        std::cout <<  "[" << RED << amount << RESET << "] Damaged... ";
        _hp -= amount;
    }
        std::cout << YELLOW << _name << RESET << "[" << GREEN << _hp << RESET << "]" << std::endl;
}

//여기도 체력이 너무 많으면 회복이 안댐!
void ClapTrap::beRepaired(unsigned int mount)
{
    std::cout << CYAN << "BE REPAIRED  >> " <<  RESET;
    if (_hp == ClapTrap::_maxhp)
    {
        std::cout << "Full Enough Hit! ";
    }
    else if (_hp + mount > ClapTrap::_maxhp)
    {
        std::cout << "[" << GREEN << ClapTrap::_maxhp - _hp << RESET << "] healing "
        << "Real Repaired [" << GREEN << mount << RESET << "] ";
        _hp = ClapTrap::_maxhp;
    }
    else
    {
        std::cout << "[" << GREEN << mount << RESET << "] healing ";
        _hp += mount;
    }
    std::cout << YELLOW << _name << RESET << "[" << GREEN << _hp << RESET << "]" << std::endl;
}

std::string ClapTrap::getName() const
{
    return (_name);
}

unsigned int ClapTrap::getHp() const
{
    return (_hp);
}

unsigned int ClapTrap::getMp() const
{
    return (_mp);
}

unsigned int ClapTrap::getAd() const
{
    return (_ad);
}