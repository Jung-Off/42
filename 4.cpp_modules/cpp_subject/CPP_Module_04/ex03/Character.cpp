#include "Character.hpp"

Character::Character()
{

}

Character::Character(const Character& a)
{

}

Character& Character::operator=(const Character& a)
{

}

Character::~Character()
{

}

std::string const & Character::getName() const
{
    return (_name);
}

void Character::equip(AMateria* m)
{

}

void Character::unequip(int idx)
{

}

void Character::use(int idx, ICharacter& target)
{

}

Character::Character(std::string name)
{

}