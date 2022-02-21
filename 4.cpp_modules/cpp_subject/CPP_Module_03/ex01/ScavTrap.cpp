
#include "ScavTrap.hpp"

//기본생성자, 생성자, 소멸자, 복사생성자, 대입연산자

ScavTrap::ScavTrap()
    : _guard(false)
{
    //ClapTrap에서 생성하고 초기화하고 여기서 덮어 씌우는 느낌!
    setAd(20);
    setMp(50);
    setHp(100);

    std::cout << "Constructor [" << BLUE << getName() << RESET << "] ScavTrap " << std::endl;   
}

ScavTrap::ScavTrap(std::string name)
    : ClapTrap(name), _guard(false)
{
    //ClapTrap에서 생성하고 초기화하고 여기서 덮어 씌우는 느낌!
    setAd(20);
    setMp(50);
    setHp(100);

    std::cout << "Constructor [" << BLUE << getName() << RESET << "] ScavTrap " << std::endl;   
}

ScavTrap::ScavTrap(const ScavTrap& st)
    : ClapTrap(st.getName()), _guard(st.getGuard())
{
    //set으로 접근하는 것이 맞는건지 그냥 접근하는게 맞는건지는 잘 모르겠~ 
    _hp = st.getHp();
    _mp = st.getMp();
    _ad = st.getAd();

    std::cout << "Copy Constructor [" << BLUE << getName() << RESET << "] ScavTrap " << std::endl;   
}

ScavTrap& ScavTrap::operator=(const ScavTrap& st)
{
    if (this == &st)
        return (*this);
    //set으로 접근하는 것이 맞는건지 그냥 접근하는게 맞는건지는 잘 모르겠~ 
    _guard = st.getGuard();
    _name = st.getName();
    _hp = st.getHp();
    _mp = st.getMp();
    _ad = st.getAd();

    std::cout << "Operator = [" << CYAN << getName() << RESET << "] ScavTrap " << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor ScavTrap " << getName() << std::endl;   
}

void ScavTrap::attack(std::string const& target)
{
    std::cout << "ScavTrap [" << RED << _name << RESET << "] attack "  << target <<
    ", causing [" << RED << _ad << RESET << "] points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (_guard)
    {
        std::cout << "No Damaged !" << std::endl;
        _guard = false;
    }
    else
        ClapTrap::takeDamage(amount);
}

void ScavTrap::guardGate()
{
    if (_guard)
        std::cout << "[" << BLUE << getName() << RESET << "]" << " Already guard";
    else
    {
        if (_mp >= ScavTrap::_guardMp)
        {
            _guard = true;
            std::cout << "Use guard ";
            _mp -= ScavTrap::_guardMp;
            std::cout << "[" << BLUE << ScavTrap::_guardMp << RESET << "] Use !";
        }
        else
        {
            _guard = false;
            std::cout << "not use guard ";
        }
    }
        std::cout << "  " << _name << " mp" << "[" << BLUE << _mp << RESET << "]" << std::endl;
}

bool ScavTrap::getGuard(void) const
{
    return (_guard);
}