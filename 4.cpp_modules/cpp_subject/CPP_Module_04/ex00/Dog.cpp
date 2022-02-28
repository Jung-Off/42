
#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog Constructor " << getType() << std::endl;
}

Dog::Dog(const Dog& a) : Animal(a.getType())
{
    std::cout << "Dog Copy Constructor " << getType() << std::endl;
}

Dog& Dog::operator=(const Dog& a)
{
    if (this != &a)
        _type = a.getType();
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog Destructor " << getType() << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Bow-wow Bow-wow" << std::endl;
}