#ifndef Cure_HPP
#define Cure_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure& operator=(const Cure& A);
        Cure(Cure& A);
        ~Cure();

        // Cure(std::string const & type);
        // void setType(std::string const type);
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target); //여기부분 구현하기 ICaracter
};

#endif