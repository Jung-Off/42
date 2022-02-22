
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


#define BRED 	"\x1b[41m"
#define BGREEN 	"\x1b[42m"
#define BYELLOW "\x1b[43m"
#define BBLUE 	"\x1b[44m"
#define BMAGENTA "\x1b[45m"
#define BCYAN 	"\x1b[46m"
#define BRESET 	"\x1b[40m"


class ClapTrap
{
    private:
        std::string _name;
        unsigned int _hp;
        unsigned int _mp;
        unsigned int _ad;
        static const int _maxhp = 50;
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
};

#endif