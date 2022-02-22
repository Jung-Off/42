
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

//orthodox 규칙 맞추기!
//default constructor
//copy contructor
//assignation operator overload
//destructor.


class FragTrap : virtual public ClapTrap
{
    private:
    public:
        FragTrap();
        FragTrap(const FragTrap& ft);
        FragTrap& operator=(FragTrap& ft);
        ~FragTrap();
        FragTrap(std::string name);

        void attack(std::string const& target);
        void takeDamage(unsigned int amount);
        void highFivesGuys(void) const;

        void setHp();
        void setAd();
};



#endif