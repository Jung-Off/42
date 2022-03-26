#include "Character.hpp"

Character::Character()
    :   _name("NONAME")
{
    _index = 0;
    for (int i = 0; i < 4; i++)
        _ablity[i] = NULL;
}

Character::Character(const Character& a)
    :   _name(a.getName())
{
    _index = a.getIndex();
    for (int i = 0; i < _index; i++)
        //a의 ablity가 있을 때만 아래의 식 사용
        //없으면 ->clone 접근할 수 없어
        _ablity[i] = a._ablity[i]->clone();
        //a 자신을 복사하는 게 클론! 클론해서 나오는 주소를 _ablity[i]에 넣어!
}

Character& Character::operator=(const Character& a)
{
    if (this != &a)
    {
        _name = a.getName();
        _index = a.getIndex();
        for (int i = 0; i < 4; i++)
        {
            //원본이 차있으면 비우는 과정!
            if (_ablity[i] != NULL)
            {
                delete _ablity[i];
                _ablity[i] = NULL;
            }
            //복사할 대상이 있을 때!
            if (a._ablity[i] != NULL)
                _ablity[i] = a._ablity[i]->clone();
        }
    }
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        delete _ablity[i];
        _ablity[i] = NULL;
    }
}

std::string const & Character::getName() const
{
    return (_name);
}

void Character::equip(AMateria* m)
{
    if (_index >= 4)
        std::cout << "full equip!!" << std::endl;
    else
        _ablity[_index++] = m;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= _index)
        std::cout << "not invaild idx unequip" << std::endl;
    else
        _ablity[idx]->setType("");
        //사용은 됨
        //_ablity[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > _index)
        std::cout << "not invaild idx use" << std::endl;
    else if (_ablity[idx]) //안들어갔을때 사용할려고 함
        _ablity[idx]->use(target);
    else    // 비어있을 때
        std::cout << "Character _ablity is empty" << std::endl;
}

Character::Character(std::string name)
    : _name(name)
{
    _index = 0;
    for (int i = 0; i < 4; i++)
        _ablity[i] = NULL;
}

int Character::getIndex() const
{
    return (_index);
}