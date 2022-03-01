
#include "Ice.hpp"

Ice::Ice() : AMateria("Ice")
    {}

Ice& Ice::operator=(const Ice& A)
{
    if (this != &A)
        _type = A.getType();
    return (*this);
}

Ice::Ice(Ice& A)
{
    _type = A.getType();
}

Ice::~Ice()
    {}

// Ice::Ice(std::string const & type) : AMateria(type)
//     {}

AMateria* Ice::clone() const
{
    Ice *ice = new Ice();
    ice->setType(_type);
    return (ice);
}

void Ice::use(ICharacter& target)
{

}

// void Ice::setType(std::string const type)
// {
//     _type = type;
// }