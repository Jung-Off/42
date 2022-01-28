#include <iostream>
#include <cstring>

int main()
{
    char str[30];

    strcpy(str, "hello");
    std::cout << str << " [len] " << strlen(str) << std::endl;

    std::cout << strcmp(str, "hello") << " " <<
    strcmp(str, "gy name is :") << std::endl;

    strcat(str, "My name is :");
    std::cout << str << " [len] " << strlen(str) << std::endl;

    std::cout << strcmp(str, "hello") << " " <<
    strcmp(str, "My name is :") << std::endl;
}