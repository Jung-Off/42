#include <iostream>

int main()
{
    std::string str("HI THIS IS BRAIN");

    std::string *stringPTR = &str;
    std::string &stringREF = *stringPTR;

    std::cout << "stringPTR Address : " << stringPTR << std::endl;
    std::cout << "stringREF Address : " << &stringREF << std::endl;

    std::cout << "stringPTR contents : " << *stringPTR << std::endl;
    std::cout << "stringREF contents : " << stringREF << std::endl;
}