
#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain* _brain;
    public:
        Dog();
        Dog(const Dog& a);
        Dog& operator=(const Dog& a);
        virtual ~Dog();
        
        virtual void makeSound() const;
        Brain& getBrain() const;  //private 인 Brain*에 접근할 수 있도록!
};

#endif