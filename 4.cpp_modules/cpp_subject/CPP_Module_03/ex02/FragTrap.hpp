
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

//orthodox 규칙 맞추기!
//default constructor
//copy contructor
//assignation operator overload
//destructor.


class FragTrap : public ClapTrap
{
    private:
        static const int _hfMp = 50;
    public:
        FragTrap();
        FragTrap(const FragTrap& ft);
        FragTrap& operator=(FragTrap& ft);
        ~FragTrap();
        FragTrap(std::string name);

        void highFivesGuys(void) const;
};



#endif