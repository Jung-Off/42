
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "Correct" << std::endl << std::endl;
    {    
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        j->makeSound();
        i->makeSound(); //will output the cat sound!
        meta->makeSound();
    }
    std::cout << std::endl << "Wrong" << std::endl << std::endl;
    {
        const WrongAnimal* meta = new WrongAnimal();
        // const Animal* j = new Dog();
        // const WrongCat* j = new WrongCat();
        const WrongAnimal* i = new WrongCat();
        // std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        // j->makeSound();
        i->makeSound();
        meta->makeSound();
    }
}

//wrong class 만들기