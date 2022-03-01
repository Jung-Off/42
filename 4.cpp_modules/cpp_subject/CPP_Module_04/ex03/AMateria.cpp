
#include "AMateria.hpp"

AMateria::AMateria() : _type("NONAME")
    {} //abstract class라 불리어질 일 없다?

AMateria& AMateria::operator=(const AMateria& A)
{
    if (this != &A)
        _type = A.getType();
    return (*this);
}

AMateria::AMateria(AMateria& A)
{
    _type = A.getType();
}

AMateria::~AMateria()
    {}

AMateria::AMateria(std::string const & type) : _type(type)
    {}

std::string const & AMateria::getType() const
{
    return (_type);
}

void AMateria::setType(std::string const type)
{
    _type = type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* AMateria " << target.getName() << std::endl;
}