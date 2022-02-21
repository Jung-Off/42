
#include "ScavTrap.hpp"

int main()
{
    ScavTrap st1;           //default Constructor
    ScavTrap st2("st2");    // ě¸ě Constructor
    ScavTrap st3(st2);      // copy Constructor

    // std::cout << "st1 Name : " << st1.getName() << " hp : " << st1.getHp()
    //  << " mp : " << st1.getMp() << " ad : " << st1.getAd() << std::endl;
    // std::cout << "st2 Name : " << st2.getName() << " hp : " << st2.getHp()
    //  << " mp : " << st2.getMp() << " ad : " << st2.getAd() << std::endl;
    // std::cout << "st3 Name : " << st3.getName() << " hp : " << st3.getHp()
    //  << " mp : " << st3.getMp() << " ad : " << st3.getAd() << std::endl;
    // st1 = st3;

    // std::cout << "st1 Name : " << st1.getName() << " hp :" << st1.getHp()
    //  << " mp : " << st1.getMp() << " ad : " << st1.getAd() << std::endl;
    // std::cout << std::endl;
    std::cout << std::endl;
    st1.attack("moster");

    st1.takeDamage(50);
    st1.guardGate();
    st1.guardGate();
    st1.takeDamage(50);
    st1.takeDamage(10);
    st1.beRepaired(1000);
    st1.guardGate();
    st1.takeDamage(50);
    st1.takeDamage(50);
    st1.takeDamage(50);

    std::cout << std::endl << std::endl;
}