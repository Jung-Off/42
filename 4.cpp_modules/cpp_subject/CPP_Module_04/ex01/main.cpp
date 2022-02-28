
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
    std::cout << "===== Normal Cat =====" << std::endl << std::endl;

        Cat cat1;
        cat1.getBrain().setCell("Muscle", 0);
        std::cout << "cat1 Brain : " << cat1.getBrain().getCell(0) << std::endl << std::endl;

        Cat cat2(cat1);
        std::cout << "cat2 Brain : " << cat2.getBrain().getCell(0) << std::endl << std::endl;

        Cat cat3;
        cat3 = cat1;
        std::cout << "cat3 Brain : " << cat3.getBrain().getCell(0) << std::endl << std::endl;

        std::cout << "Cat1 brain Address " << &cat1.getBrain() << std::endl;
        std::cout << "Cat2 brain Address " << &cat2.getBrain() << std::endl;
        std::cout << "Cat3 brain Address " << &cat3.getBrain() << std::endl << std::endl;


    std::cout << "===== Pointer Cat =====" << std::endl << std::endl;

        Cat *pcat1 = new Cat();
        pcat1->getBrain().setCell("Muscle", 0);
        std::cout << "cat1 Brain : " << pcat1->getBrain().getCell(0) << std::endl << std::endl;
        
        //복사
        Cat *pcat2 = new Cat(*pcat1);
        std::cout << "cat2 Brain : " << pcat2->getBrain().getCell(0) << std::endl << std::endl;

        //대입 >> 복사
        // Cat *cat3 = NULL;
        // cat3 = new Cat(*cat1);
        // std::cout << "cat3 Brain : " << cat3->getBrain().getCell(0) << std::endl << std::endl;

        std::cout << "Cat1 brain Address " << &(pcat1->getBrain()) << std::endl;
        std::cout << "Cat2 brain Address " << &(pcat2->getBrain()) << std::endl;
        // std::cout << "Cat3 brain Address " << &(cat3->getBrain()) << std::endl << std::endl;
    
        std::cout << std::endl;
        delete pcat1;
        delete pcat2;
        // delete pcat1;
        // delete pcat2;

        // delete cat3;


    std::cout << "===== Normal Dog =====" << std::endl << std::endl;

        Dog Dog1;
        Dog1.getBrain().setCell("Muscle", 0);
        std::cout << "Dog1 Brain : " << Dog1.getBrain().getCell(0) << std::endl << std::endl;

        Dog Dog2(Dog1);
        std::cout << "Dog2 Brain : " << Dog2.getBrain().getCell(0) << std::endl << std::endl;

        Dog Dog3;
        Dog3 = Dog1;
        std::cout << "Dog3 Brain : " << Dog3.getBrain().getCell(0) << std::endl << std::endl;

        std::cout << "Dog1 brain Address " << &Dog1.getBrain() << std::endl;
        std::cout << "Dog2 brain Address " << &Dog2.getBrain() << std::endl;
        std::cout << "Dog3 brain Address " << &Dog3.getBrain() << std::endl << std::endl;

    std::cout << "===== Pointer Dog =====" << std::endl << std::endl;
    
        Dog *pDog1 = new Dog();
        pDog1->getBrain().setCell("Muscle", 0);
        std::cout << "Dog1 Brain : " << pDog1->getBrain().getCell(0) << std::endl << std::endl;
        
        //복사
        Dog *pDog2 = new Dog(*pDog1);
        std::cout << "Dog2 Brain : " << pDog2->getBrain().getCell(0) << std::endl << std::endl;

        //대입 >> 복사
        // Dog *Dog3 = NULL;
        // Dog3 = new Dog(*Dog1);
        // std::cout << "Dog3 Brain : " << Dog3->getBrain().getCell(0) << std::endl << std::endl;

        std::cout << "Dog1 brain Address " << &(pDog1->getBrain()) << std::endl;
        std::cout << "Dog2 brain Address " << &(pDog2->getBrain()) << std::endl;
        // std::cout << "Dog3 brain Address " << &(Dog3->getBrain()) << std::endl << std::endl;
    
        std::cout << std::endl;
        delete pDog1;
        delete pDog2;
        
        // delete pDog1;
        // delete pDog2;

        // delete Dog3;
    

    std::cout << "\n------- Polymorphism ----------\n";
    
    Animal *animal[10];

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
        // delete animal[1];
        // delete animal[3];
        // delete animal[8];
        // delete animal[9];
    
    // std::cout << system("leaks Brain") << std::endl;
    // while(1);
}
