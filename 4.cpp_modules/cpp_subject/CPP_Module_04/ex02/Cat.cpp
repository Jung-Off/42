
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    //brain 공간 만들기
    _brain = new Brain();
    std::cout << "Cat Constructor " << getType() << std::endl;
}

Cat::Cat(const Cat& a) : Animal(a.getType())
{
    //대입연산자로 넘기기
    //*this = a;

    //공간만들고
    // _brain = new Brain();
    //여기서 복사
    // for(int i = 0; i < CELL_MAX; i++)
    //     _brain->setCell(a.getBrain().getCell(i), i);

    //Brain의 복사연산자
    _brain = new Brain(a.getBrain());
    std::cout << "Cat Copy Constructor " << getType() << std::endl;
}

Cat& Cat::operator=(const Cat& a)
{
    std::cout << "Cat = operator " << getType() << std::endl;
    if (this != &a)
    {
        // _brain = a._brain;  //소멸할때 문제가 생김!  //얕은 복사
        _type = a.getType();
        // for(int i = 0; i < CELL_MAX; i++)
        //     _brain->setCell(a.getBrain().getCell(i), i);
        //brain의 대입연산자를 이용할 순 없을까?
        // *_brain = *(a._brain);
        *_brain = a.getBrain();    //이런식으로 하면 brain 대입 연산자
        
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