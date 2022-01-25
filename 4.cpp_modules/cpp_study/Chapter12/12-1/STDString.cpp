#include <iostream>
#include <string>

int main()
{
    std::string str1 = "I like ";
    std::string str2 = "string class";
    std::string str3 = str1 + str2;

    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
    std::cout << str3 << std::endl;

    str1+=str2;
    if (str1==str3)
        std::cout << "동일 문자열!" << std::endl;
    else
        std::cout << "동일하지 않은 문자열!" << std::endl;
    
    std::string str4;
    std::cout << "문자열 입력: ";
    std::cin >> str4;
    std::cout << "입력한 문자열 : " << str4 << std::endl;
    return 0;
}