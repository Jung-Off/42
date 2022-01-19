#include <iostream>

int main()
{
    char name[100];
    char number[100];

    std::cout << "이름이 무엇이요 ? : ";
    std::cin >> name;

    std::cout << "전화번호가 무엇이요 ? : ";
    std::cin >> number;

    std::cout << "이름 : " << name ;
    std::cout << " 전화번호 : " << number ;
}