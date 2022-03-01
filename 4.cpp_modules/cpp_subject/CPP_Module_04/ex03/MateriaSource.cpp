
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
    : _index(0)
{
    for (int i = 0; i < 4; i++)
        _ablity[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& M)
    : _index(M.getIndex())
{
    for (int i = 0; i < _index; i++)
        _ablity[i] = M._ablity[i]->clone();
}

MateriaSource& MateriaSource::operator=(const MateriaSource& M)
{
    if (this != &M)
    {
        _index = M.getIndex();
        for (int i = 0; i < 4; i++)
        {
            if(_ablity[i] != NULL)
            {
                delete _ablity[i];
                _ablity[i] = NULL;
            }
            if (M._ablity[i] != NULL)
                _ablity[i] = M._ablity[i]->clone();
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        delete _ablity[i];
        _ablity[i] = NULL;
    }
}

void MateriaSource::learnMateria(AMateria* A)
{
    if (_index >= 4)
        std::cout << "Material is full! not learn!" << std::endl;
    else
        _ablity[_index++] = A->clone();
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    if (_index == 0)
    {
        std::cout << "AMateria is empty! Learn First!" << std::endl;
        return (0);
    }
    for (int i = 0; i < _index; i++)
    {
        if (_ablity[i] && _ablity[i]->getType() == type)
            return (_ablity[i]->clone());
    }
    std::cout << "There is no suitable type : " << type << std::endl;
    return (0);
}

int MateriaSource::getIndex() const
{
    return (_index);
}