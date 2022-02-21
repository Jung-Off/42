
#include "ScavTrap.hpp"

int main()
{
    ScavTrap st1;           //default Constructor
    ScavTrap st2("st2");    // 인잝 Constructor
    ScavTrap st3(st2);      // copy Constructor

    st1 = st3;

     std::cout << std::endl;
    st1.attack("moster");

    
    // st1.takeDamage(50); //100
    // st1.guardGate(); //guard_mode on -> used energy point 
    // st1.guardGate(); //warning message
    // st1.takeDamage(50); //no damage -> guard_mode off
    // st1.beRepaired(10); //10points be repaired
    // st1.beRepaired(1000); //be repaired to maxHP
    // st1.guardGate(); // guard_mode on -> used energy point 
    // st1.takeDamage(50); //no damage -> guard_mode off
    // st1.guardGate(); //can't get into guard_mode
    // st1.takeDamage(1000); //died 
    std::cout << std::endl;


}