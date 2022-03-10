#include "utils.hpp"

Base *generate()
{
    std::srand(std::time(NULL));
    int randnum = std::rand() % 3;

    Base* ret(NULL);
    if (randnum == 0)
    {
        ret = new A();
        std::cout << "generate A" << std::endl;
    }
    else if (randnum == 1)
    {
        ret = new B();
        std::cout << "generate B" << std::endl;
    }
    else
    {
        ret = new C();
        std::cout << "generate C" << std::endl;
    }
    return (ret);
}

void identify(Base* p)
{
    std::cout << "Pointer -> Base Real Type is : ";

    A* a = dynamic_cast<A*>(p);
    if (a != NULL)
        std::cout << " A A A !" << std::endl;
    B* b = dynamic_cast<B*>(p);
    if (b != NULL)
        std::cout << " B B B !" << std::endl;
    C* c = dynamic_cast<C*>(p);
    if (c != NULL)
        std::cout << " C C C !" << std::endl;
}

void identify(Base& p)
{
    std::cout << "Reference -> Base Real Type is : ";
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void) a;
        std::cout << " A A A !" << std::endl;
    }
    catch(std::bad_cast e)
    {}
    try
    {
        B& b = dynamic_cast<B&>(p);
        (void) b;
        std::cout << " B B B !" << std::endl;
    }
    catch(std::bad_cast e)
    {}
    try
    {
        C& c = dynamic_cast<C&>(p);
        (void) c;
        std::cout << " C C C !" << std::endl;
    }
    catch(std::bad_cast e)
    {}
}
