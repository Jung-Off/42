
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        AMateria* _ablity[4];
        std::string _name;
    public:
        Character();
        Character(const Character& a);
        Character& operator=(const Character& a);

        virtual ~Character();
        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);

        Character(std::string name);
};

#endif