#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
  {
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");    //무기 체인지
    bob.attack();
  }
  {
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club"); //무기 체인지
    jim.attack();
  }
}

// int main()
// {
//     Weapon Sword;
//     Weapon Gun("Gun");

//     std::cout << std::endl;
//     std::cout << "===== HumanA =====" << std::endl;
//     std::cout << "===== HumanA Name(NO), Weapon(YES) Type (No) =====" << std::endl << std::endl;
//     HumanA HeroAnoNameWeaponNo(Sword);

//     std::cout << "===== HumanA Name(Yes), Weapon(YES) Type (No) =====" << std::endl << std::endl;
//     HumanA HeroANamenoWeapon("Orc", Sword);

//     std::cout << "===== HumanA Name(No), Weapon(YES) Type (Yes) =====" << std::endl << std::endl;
//     HumanA HeroAnoNameWeapon(Gun);

//     std::cout << "===== HumanA Name(Yes), Weapon(YES) Type (Yes) =====" << std::endl << std::endl;
//     HumanA HeroANameWeapon("Gunner", Gun);

//     std::cout << "===== HumanA =====" << std::endl << std::endl << std::endl;

// }