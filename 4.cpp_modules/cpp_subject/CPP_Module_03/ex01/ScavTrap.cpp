
#include "ScavTrap.hpp"

//기본생성자, 생성자, 소멸자, 복사생성자, 대입연산자

ScavTrap::ScavTrap()
   :    _guard(false)
{
    setName("NONAME");
    setDamage(20);
    setEnergy(50);
    setHit(100);

    std::cout << "Constructor [" << BLUE << getName() << RESET << "] ScavTrap " << std::endl;   
}

ScavTrap::ScavTrap(std::string name)
    :   ClapTrap(name), _guard(false)
{
    // ClapTrap::setDamage(20);
    // ClapTrap::setEnergy(50);
    // ClapTrap::setHit(100);
    setDamage(20);
    setEnergy(50);
    setHit(100);
    std::cout << "Constructor [" << BLUE << getName() << RESET << "] ScavTrap " << std::endl;   
}

ScavTrap& ScavTrap::operator=(const ScavTrap& a)
{
    if(this == &a)
        return (*this);
    // this->setName(a.getName());  //protected로 제한자를 설정안했을 때!
    // this->setHit(a.getHit());
    // this->setEnergy(a.getEnergy());
    // this->setDamage(a.getDamage());
    _guard = a._guard;
    _name = a.getName();
    _hitPoints = a.getHit();
    _energyPoint = a.getEnergy();
    _attackDamage = a.getDamage();

    std::cout << "Operator = [" << CYAN << _name << RESET << "] ClapTrap " << std::endl;
    return (*this);
}

void ScavTrap::attack(std::string const& target)
{
     std::cout << "ScavTrap [" << RED << _name << RESET << "] attack "  << target <<
    ", causing [" << RED << _attackDamage << RESET << "] points of damage!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor ScavTrap " << _name << std::endl;   
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (_guard)
    {
        std::cout << _name << "  Guard mode! ";
        std::cout << _name << " is attacked, but not damaged at all." << std::endl;
        _guard = false;
    }
    else
        ClapTrap::takeDamage(amount);
}

void ScavTrap::guardGate()
{
    if (_guard)
    {
        std::cout << "Guard already On" << std::endl;
    }
    else
    {
        if (_energyPoint >= ScavTrap::_guardEnergy)
        {
            _guard = true;
            _energyPoint -= ScavTrap::_guardEnergy;
            std::cout << "Turn On Guard!!!" << std::endl;
        }
        else
        {
            _guard = false;
            std::cout << "Not enough Energy" << std::endl;
        }
    }
}