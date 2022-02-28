
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(const Animal& a);
        Animal& operator=(const Animal& a);
        ~Animal();
        Animal(std::string type);
        
        std::string getType() const;
        virtual void makeSound() const;
};

#endif