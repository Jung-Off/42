#include <iostream>

int val = 100;

int main()
{
    int val = 20;
    val += 3;
    ::val += 3;

    std::cout << "지역변수 : " << val << std::endl;
    std::cout << "전역변수 : " << ::val << std::endl;
}