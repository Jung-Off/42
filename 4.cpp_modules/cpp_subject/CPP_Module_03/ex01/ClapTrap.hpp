
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
    protected:
        std::string _name;
        unsigned int _hp;
        unsigned int _mp;
        unsigned int _ad;
        static const int _maxhp = 100;
    public:
        ClapTrap();
        ClapTrap(const ClapTrap& ct);
        ClapTrap& operator=(const ClapTrap& ct);
        ~ClapTrap();
        ClapTrap(std::string name); //추가 생성자

        //멤버함수
        void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        //getter
        //복사 or = 여기서 사용
        std::string getName() const;
        unsigned int getHp() const;
        unsigned int getMp() const;
        unsigned int getAd() const;

        void setName(std::string n);
        void setHp(unsigned int h);
        void setMp(unsigned int m);
        void setAd(unsigned int a);
};

#endif