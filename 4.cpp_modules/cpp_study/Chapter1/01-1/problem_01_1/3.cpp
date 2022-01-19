#include <iostream>

int main()
{
    int input;

    std::cout << "몇 단을 출력할까요 ? : ";
    std::cin >> input;

    for (int i = 1; i < 10; i++)
    {
        int multi = 0;
        multi = i * input;
        std::cout << "[" << i << "]" << multi << std::endl;
    }
}