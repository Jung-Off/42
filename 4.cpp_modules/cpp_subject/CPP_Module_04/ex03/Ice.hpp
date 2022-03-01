#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice& operator=(const Ice& A);
        Ice(Ice& A);
        ~Ice();

        // Ice(std::string const & type);
        // void setType(std::string const type);
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target); //여기부분 구현하기 ICaracter
};

#endif