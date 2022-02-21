
#include "ClapTrap.hpp"

int main()
{
   // std::cout << "Constructor Check" << std::endl;

    ClapTrap ct1; //default Constructor
    ClapTrap ct2("claptrap2"); // Copy Constructor
    ClapTrap ct3(ct2); // copy Constructor
    // std::cout << std::endl;

    // std::cout << ct1.getName() << std::endl;
    // std::cout << ct2.getName() << std::endl;
    // std::cout << ct3.getName() << std::endl;
    // std::cout << std::endl;

    ct1 = ct3;
    // std::cout << "Operator [ct1] = [ct3] Check" << std::endl;
    // std::cout << ct1.getName() << std::endl;
    // std::cout << ct2.getName() << std::endl;
    // std::cout << ct3.getName() << std::endl;
    std::cout << std::endl;


    //a1 10
    ct2.attack("Mulder");

    ct2.takeDamage(5); // ct2 5
    ct2.beRepaired(10); // ct2 15

    ct2.takeDamage(22); // ct2 0
    ct2.takeDamage(3); // ct2 died
    ct2.beRepaired(13); // 13
    ct2.beRepaired(13); // 26
    ct2.beRepaired(13); // 39
    ct2.beRepaired(13); // 50
    std::cout << std::endl;

}