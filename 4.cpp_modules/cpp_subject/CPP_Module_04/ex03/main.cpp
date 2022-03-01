#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


int main()
{
    IMateriaSource* src = new MateriaSource();
    //대장간 오픈
    AMateria* tmp;
    //기술!
    ICharacter* me = new Character("me");
    //나 생성
    ICharacter* bob = new Character("bob");
    //bob생성
    
    //배우기전 생성
    tmp = src->createMateria("ice");
    //ice기술
    me->equip(tmp);
    //ice 기술 익히기
    me->use(0, *bob);
    std::cout << std::endl;

    src->learnMateria(new Ice());
    //기술 배우기
    tmp = src->createMateria("ice");
    //ice기술
    me->equip(tmp);
    //ice 기술 익히기
    me->use(1, *bob);
    //사용하기
    std::cout << std::endl;

    src->learnMateria(new Cure());
    //기술 배우기
    tmp = src->createMateria("aaa");
    //aaa기술
    me->equip(tmp);
    //aaa 기술 익히기
    me->use(2, *bob);
    std::cout << std::endl;

    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->use(3, *bob);

    delete bob; delete me; delete src;
    return 0;
}