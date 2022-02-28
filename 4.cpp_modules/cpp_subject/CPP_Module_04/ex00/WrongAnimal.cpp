#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << "WrongAnimal Constructor " << getType() << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& a) : _type(a.getType())
{
    std::cout << "WrongAnimal Copy Constructor " << getType() << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a)
{
    if (this != &a)
        _type = a.getType();
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor " << getType() << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << "WrongAnimal Constructor " << getType() << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (_type);
}

void WrongAnimal::makeSound() const
{
    std::cout << getType() << " make Sound" << std::endl;
}