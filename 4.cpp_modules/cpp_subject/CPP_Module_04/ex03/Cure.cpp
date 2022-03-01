
#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
    {}

Cure& Cure::operator=(const Cure& A)
{
    if (this != &A)
        _type = A.getType();
    return (*this);
}

Cure::Cure(Cure& A)
{
    _type = A.getType();
}

Cure::~Cure()
    {}

// Cure::Cure(std::string const & type) : AMateria(type)
//     {}

AMateria* Cure::clone() const
{
    Cure *cure = new Cure();
    cure->setType(_type);
    return (cure);
}

void Cure::use(const ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

// void Cure::setType(std::string const type)
// {
//     _type = type;
// }