
#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    //brain 공간 만들기
    _brain = new Brain();
    std::cout << "Dog Constructor " << getType() << std::endl;
}

Dog::Dog(const Dog& a) : Animal(a.getType())
{
    //대입연산자로 넘기기
    //*this = a;

    //공간 만들고
    // _brain = new Brain();
    // 여기서 복사
    // for(int i = 0; i < CELL_MAX; i++)
    //     _brain->setCell(a.getBrain().getCell(i), i);

    //Brain의 복사연산자
    _brain = new Brain(a.getBrain());
    std::cout << "Dog Copy Constructor " << getType() << std::endl;
}

Dog& Dog::operator=(const Dog& a)
{
    std::cout << "Dog = operator " << getType() << std::endl;
    if (this != &a)
    {
        // _brain = a._brain;  //소멸할때 문제가 생김!  //얕은 복사
        _type = a.getType();
        // for(int i = 0; i < CELL_MAX; i++)
            // _brain->setCell(a.getBrain().getCell(i), i);
        //brain의 대입연산자를 이용할 순 없을까?
        // *_brain = *(a._brain);
        *_brain = a.getBrain(); //이런식으로 하면 brain 대입 연산자
        
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