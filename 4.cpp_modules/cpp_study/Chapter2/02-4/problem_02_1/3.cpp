#include <iostream>

//int *(&a1) = *ptr;
//ptr의 다른이름 a1

// 이건 말 그대로 값을 바꾸는 거고

// void SwapPointer(int *(&a1), int *(&a2))
// {
//     int temp;

//     temp = *a1;
//     *a1 = *a2;
//     *a2 = temp;
// }

// 이건 주소를 바꾸는 거 같음
// 가리키는 대상을 바꿈

void SwapPointer(int *(&a1), int *(&a2))
{
    int *temp;

    temp = a1;
    a1 = a2;
    a2 = temp;
}

int main()
{
    int num1 = 5;
    int *ptr1 = &num1;
    int num2 = 10;
    int *ptr2 = &num2;

    std::cout << num1 << " " << num2 << std::endl;
    std::cout << &num1 << " " << &num2 << std::endl;
    std::cout << *ptr1 << " " << *ptr2 << std::endl;
    std::cout << &(*ptr1) << " " << &(*ptr2) << std::endl;

    SwapPointer(ptr1, ptr2);

    std::cout << num1 << " " << num2 << std::endl;
    std::cout << &num1 << " " << &num2 << std::endl;
    std::cout << *ptr1 << " " << *ptr2 << std::endl;
    std::cout << &(*ptr1) << " " << &(*ptr2) << std::endl;

}