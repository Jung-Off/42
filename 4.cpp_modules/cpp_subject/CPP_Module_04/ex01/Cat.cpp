
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    //brain 공간 만들기
    _brain = new Brain();
    std::cout << "Cat Constructor " << getType() << std::endl;
}

Cat::Cat(const Cat& a) : Animal(a.getType())
{
    _brain = new Brain(a.getBrain());
    // _brain = new Brain();
    //*this = a;
    // for(int i = 0; i < CELL_MAX; i++)
    //     _brain->setCell(a.getBrain().getCell(i), i);
    std::cout << "Cat Copy Constructor " << getType() << std::endl;
}

Cat& Cat::operator=(const Cat& a)
{
    std::cout << "Cat = operator " << getType() << std::endl;
    if (this != &a)
    {
        _type = a.getType();
        // _brain = a._brain;  //소멸할때 문제가 생김!  //얕은 복사
            //brain의 대입연산자를 이용할 순 없을까?
            // *_brain = *(a._brain);
            *_brain = a.getBrain();    //이런식으로 하면 brain 대입 연산자
        // for(int i = 0; i < CELL_MAX; i++)
        //     _brain->setCell(a.getBrain().getCell(i), i);
    }
    return (*this);
}

Cat::~Cat()
{
    //생성했으니까 제거 dog도 똑같음
    delete _brain;
    std::cout << "Cat Destructor " << getType() << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow~ Meow~" << std::endl;
}

Brain& Cat::getBrain() const
{
    return (*_brain);
}