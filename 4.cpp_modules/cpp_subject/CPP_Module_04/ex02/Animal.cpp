#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "Animal Constructor " << getType() << std::endl;
}

Animal::Animal(const Animal& a) : _type(a.getType())
{
    std::cout << "Animal Copy Constructor " << getType() << std::endl;
}

Animal& Animal::operator=(const Animal& a)
{
    if (this != &a)
        _type = a.getType();
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal Destructor " << getType() << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Animal Constructor " << getType() << std::endl;
}

std::string Animal::getType() const
{
    return (_type);
}

// void Animal::makeSound() const
// {
//     std::cout << getType() << " make Sound" << std::endl;
// }