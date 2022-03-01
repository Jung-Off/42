
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{ 
    // Animal *ani = new Animal(); //abstract class

    Animal *a = new Dog();
    std::cout << a->getType() << std::endl;
    a->makeSound();
    std::cout << std::endl;

    Animal *b = new Cat();
    std::cout << b->getType() << std::endl;
    b->makeSound();
    std::cout << std::endl;

    delete a;
    delete b;
    std::cout << std::endl;

    Animal *animal[10];
    
    // animal[0] = new Animal();

    for (int i = 0; i < 10; ++i)
    {
        if (i % 2 == 0)
        {
            animal[i] = new Dog();
            std::cout << i << " : ";
            animal[i]->makeSound();
            std::cout << std::endl;
        }
        else
        {
            animal[i] = new Cat();
            std::cout << i << " : ";
            animal[i]->makeSound();
            std::cout << std::endl;
        }
    }

    for (int i = 0; i < 10; ++i)
    {   
        std::cout << "==== " << i << " ====" << std::endl;
        delete animal[i];
        std::cout << "====  ====" << std::endl << std::endl;
    }
    
    // std::cout << system("leaks Abstract") << std::endl;
    // while(1);
}
