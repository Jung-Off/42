
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria*   _ablity[4];
        int         _index;
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& M);
        MateriaSource& operator=(const MateriaSource& M);

        virtual ~MateriaSource();
        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type);

        int getIndex() const;
};

#endif