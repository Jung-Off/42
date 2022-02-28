
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:   
        Brain* _brain;
   	public:
        Cat();
        Cat(const Cat& a);
        Cat& operator=(const Cat& a);
        virtual ~Cat();
        
        virtual void makeSound() const;
        Brain& getBrain() const;
};

#endif