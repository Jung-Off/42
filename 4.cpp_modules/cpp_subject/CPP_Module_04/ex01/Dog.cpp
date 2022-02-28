
#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    //brain 공간 만들기
    _brain = new Brain();
    std::cout << "Dog Constructor " << getType() << std::endl;
}

Dog::Dog(const Dog& a) : Animal(a.getType())
{
    _brain = new Brain();
    //*this = a;

    for(int i = 0; i < CELL_MAX; i++)
        _brain->setCell(a.getBrain().getCell(i), i);
    std::cout << "Dog Copy Constructor " << getType() << std::endl;
}

Dog& Dog::operator=(const Dog& a)
{
    std::cout << "Dog = operator " << getType() << std::endl;
    if (this != &a)
    {
        _type = a.getType();
        //_brain = a._brain;

        for(int i = 0; i < CELL_MAX; i++)
            _brain->setCell(a.getBrain().getCell(i), i);
    }
    return (*this);
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog Destructor " << getType() << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Bow-wow Bow-wow" << std::endl;
}

Brain& Dog::getBrain() const
{
    return (*_brain);
}