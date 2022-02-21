
#include "ScavTrap.hpp"

//기본생성자, 생성자, 소멸자, 복사생성자, 대입연산자

ScavTrap::ScavTrap()
    : _guard(false)
{
    _hp = 100;
    _mp = 50;
    _ad = 20;

    std::cout << "Constructor [" << BLUE << getName() << RESET << "] ScavTrap " << std::endl;   
}

ScavTrap::ScavTrap(const ScavTrap& st)
    : ClapTrap(st.getName()), _guard(st.getGuard())
{
    _hp = st.getHp();
    _mp = st.getMp();
    _ad = st.getAd();
}

ScavTrap& ScavTrap::operator=(const ScavTrap& st)
{
    
    _hp = st.getHp();
    _mp = st.getMp();
    _ad = st.getAd();
}

ScavTrap::~ScavTrap()
{

}

bool ScavTrap::getGuard(void)
{
    return (_guard);
}