
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        int         _index;
        AMateria*   _ablity[4]; //이부분 딥카피 해야댐
    public:
        Character();
        Character(const Character& a);
        Character& operator=(const Character& a);

        ~Character();
        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);

        Character(std::string name);

        int getIndex() const;
};

#endif