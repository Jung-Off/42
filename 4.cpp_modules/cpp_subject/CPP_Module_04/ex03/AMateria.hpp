#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

# include "ICharacter.hpp"
# include "IMateriaSource.hpp"

class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria();
        AMateria& operator=(const AMateria& A);
        AMateria(AMateria& A);
        virtual ~AMateria();

        AMateria(std::string const & type);
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(const ICharacter& target); //여기부분 구현하기 ICaracter

        void setType(std::string const type);
};

#endif