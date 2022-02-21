
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::string a = "a";
    std::string b = "b";
    std::string c = "c";

    ClapTrap st4(a);
    ClapTrap st1(st4);           //default Constructor
    ScavTrap st2(b);    // ě¸ě Constructor
    FragTrap st5(c);
    FragTrap st3;      // copy Constructor
    st3 = st5;

    std::cout << std::endl;
    std::cout << " ======= " << st1.getName() << " attack =======" << std::endl;

    st1.attack(b);
    st2.guardGate();
    st2.takeDamage(st1.getAd());

    st1.attack(c);
    st3.takeDamage(st1.getAd());
    std::cout << std::endl;
    std::cout << " ======= " << st2.getName() << " attack =======" << std::endl;

    st2.attack(a);
    st1.takeDamage(st2.getAd());

    st2.attack(c);
    st3.takeDamage(st2.getAd());

    std::cout << std::endl;
    std::cout << " ======= " << st3.getName() << " attack =======" << std::endl;

    st3.highFivesGuys();
    st3.attack(a);
    st1.takeDamage(st3.getAd());

    st3.attack(b);
    st2.takeDamage(st3.getAd());
    std::cout << std::endl;

}