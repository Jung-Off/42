#include <iostream>

namespace   AAA
{
    namespace   BBB
    {
        namespace   CCC
        {
            int num1;
            int num2;
        }
    }
}

int main()
{
    AAA::BBB::CCC::num1 = 20;
    AAA::BBB::CCC::num2 = 30;

    namespace ABC = AAA::BBB::CCC;
    std::cout << ABC::num1 << std::endl;
    std::cout << ABC::num2 << std::endl;
    return 0;
}