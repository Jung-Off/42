#include <iostream>

void increase(int &a)
{
    a += 1;
}

void minus(int &a)
{
    a *= (-1);
}

int main()
{
    int a = 10;

    std::cout << 10 << " " << a << std::endl;
    increase(a);
    increase(a);
    minus(a);
    std::cout << -12  << " " << a << std::endl;
    increase(a);
    increase(a);
    increase(a);
    std::cout << -9 << " " << a << std::endl;
    minus(a);
    std::cout << 9 << " " << a << std::endl;
}