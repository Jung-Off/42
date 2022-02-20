
#include "ClapTrap.hpp"

int main()
{
    ClapTrap a1("apple");
    ClapTrap a2("banana");

    //a1 10
    a1.attack(a2.getName());

    a1.beRepaired(20); //a1 30

    a1.takeDamage(10);  //a1 20
    a1.takeDamage(10);  //a1 10
    a1.takeDamage(10);  //a1 0
    a1.takeDamage(10);  //a1 died

    a1.beRepaired(20);  //a1 20
    a1.beRepaired(20);  //a1 40
    a1.beRepaired(20);  //a1 50
    a1.beRepaired(20);  //a1 50

    a1.takeDamage(10);  //a1 40
    a1.takeDamage(10);  //a1 30
    a1.takeDamage(10);  //a1 20
    a1.takeDamage(10);  //a1 10
    a1.takeDamage(10);  //a1 0
    a1.takeDamage(10);  //a1 died

}