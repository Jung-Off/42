
#include "DiamondTrap.hpp"

int main()
{
    std::string ap = "a";

    DiamondTrap a(ap);
    DiamondTrap b(a);
    DiamondTrap c;

    c = a;
    std::cout << std::endl;
    // check
    // std::cout << "===== " << "Name : " << a.getName() << " ====" << std::endl;
    // std::cout << "===== " << "Hp : " << a.getHp() << " ====" << std::endl;
    // std::cout << "===== " << "Mp : " << a.getMp() << " ====" << std::endl;
    // std::cout << "===== " << "Ad : " << a.getAd() << " ====" << std::endl;

    a.whoAmI();
    std::cout << std::endl;

    a.attack("Hello");
    a.guardGate();
    a.highFivesGuys();

    a.takeDamage(30);
    a.guardGate();
    a.guardGate();
    a.takeDamage(10);
    a.guardGate();
    a.takeDamage(40);

    std::cout << std::endl;
}