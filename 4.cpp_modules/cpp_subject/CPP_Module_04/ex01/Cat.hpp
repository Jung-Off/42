
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
   public:
        Cat();
        Cat(const Cat& a);
        Cat& operator=(const Cat& a);
        ~Cat();
        
        virtual void makeSound() const;
};

#endif