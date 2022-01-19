#include <iostream>

int main()
{
    int sum = 0;
    for (int i = 1; i <= 5 ; i++)
    {
        int a = 0;
        std::cout << i << " 번째 정수 입력 : ";
        std::cin >> a; 
        sum += a;
    }
    std::cout << "합계 : " << sum << std::endl;
}