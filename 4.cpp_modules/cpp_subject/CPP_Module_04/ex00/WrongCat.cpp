
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat Constructor " << getType() << std::endl;
}

WrongCat::WrongCat(const WrongCat& a) : WrongAnimal(a.getType())
{
    std::cout << "WrongCat Copy Constructor " << getType() << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& a)
{
    if (this != &a)
        _type = a.getType();
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor " << getType() << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow~ Meow~" << std::endl;
}