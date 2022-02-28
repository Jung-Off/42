
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat Constructor " << getType() << std::endl;
}

Cat::Cat(const Cat& a) : Animal(a.getType())
{
    std::cout << "Cat Copy Constructor " << getType() << std::endl;
}

Cat& Cat::operator=(const Cat& a)
{
    if (this != &a)
        _type = a.getType();
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat Destructor " << getType() << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow~ Meow~" << std::endl;
}