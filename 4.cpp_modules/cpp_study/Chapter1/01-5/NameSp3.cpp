#include <iostream>

namespace BestComImpl
{
    void SimpleFunc(void);
}

namespace BestComImpl
{
    void PrettyFunc(void);
}

namespace ProgComImpl
{
    void SimpleFunc(void);
}

int main(void)
{
    BestComImpl::SimpleFunc();
}

void BestComImpl::SimpleFunc(void)
{
    std::cout << "BestCom이 정의한 함수" << std::endl;
    PrettyFunc();               //  동일 공간
    ProgComImpl::SimpleFunc();  //  다른 이름공간
}

void BestComImpl::PrettyFunc(void)
{
    std::cout << "So Pretty!!" << std::endl;
}

void ProgComImpl::SimpleFunc(void)
{
    std::cout << "ProgCom이 정의한 함수" << std::endl;
}

// namespace Parent
// {
//     int num = 2;

//     namespace SubOne
//     {
//         int num = 3;
//     }

//     namespace SubTwo
//     {
//         int num = 4;
//     }
// }

// int main()
// {
//     std::cout << Parent::num;
//     std::cout << Parent::SubOne::num;
//     std::cout << Parent::SubTwo::num;
// }