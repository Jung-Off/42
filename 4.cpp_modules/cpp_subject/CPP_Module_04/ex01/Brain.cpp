
#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Constructor" << std::endl;
    for (int i = 0; i < CELL_MAX; i++)
        _cell[i] = " ";
}

//복사인데 자기 자신이 들어올 수가 없는거고
Brain::Brain(const Brain& a)
{
    //*this = Brain;
    std::cout << "Copy Brain Constructor" << std::endl;
    for (int i = 0; i < CELL_MAX; i++)
        _cell[i] = a.getCell(i);
}

//대입하는 건데 자기 자신과 같으면 굳이 대입을 할 필요가 없다
Brain& Brain::operator=(const Brain& a)
{
    std::cout << "Brain = operator" << std::endl;
    if (this != &a)
    {
        for (int i = 0; i < CELL_MAX; i++)
            _cell[i] = a.getCell(i);
    }
    return (*this);    
}

Brain::~Brain()
{
    std::cout << "Brain Destructor" << std::endl;
}

std::string Brain::getCell(int i) const
{
    if (i < 0 || i > CELL_MAX)
    {
        std::cout << "out of Bound get" << std::endl;
        return (NULL);
    }
    return (_cell[i]);
}

void Brain::setCell(std::string cell, int i)
{
    if (i < 0 || i > CELL_MAX)
    {
        std::cout << "out of Bound set" << std::endl;
        return ;
    }
    _cell[i] = cell;
}