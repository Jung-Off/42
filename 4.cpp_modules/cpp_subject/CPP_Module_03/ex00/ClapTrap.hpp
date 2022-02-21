
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

//orthodox 규칙 맞추기!
//default constructor
//copy contructor
//assignation operator overload
//destructor.

#define RED 	"\x1b[31m"
#define GREEN 	"\x1b[32m"
#define YELLOW 	"\x1b[33m"
#define BLUE 	"\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN	"\x1b[36m"
#define RESET 	"\x1b[0m"

class ClapTrap
{
    private:
        std::string _name;          //이름
        unsigned int _hitPoints;    //체력
        unsigned int _energyPoint;  //마나
        unsigned int _attackDamage; //공격력
        static const unsigned int _maxHit = 50; //최대체력
    public:
        //기본생성자, 생성자, 소멸자, 복사생성자, 대입연산자

        ClapTrap();
        ClapTrap(std::string name);
        ~ClapTrap();
        ClapTrap(const ClapTrap& a);
        ClapTrap& operator=(const ClapTrap& b);

        void attack(std::string const& target); //상대방에게 공격을 가하는
        void takeDamage(unsigned int amount);   //상대방에게 공격을 당하는
        void beRepaired(unsigned int mount);    //체력이 올라감

        //add function
        std::string getName() const;
        unsigned int getDamage() const;
        unsigned int getHit() const;
        unsigned int getEnergy() const;
        unsigned int getMaxH() const;
        
};

#endif