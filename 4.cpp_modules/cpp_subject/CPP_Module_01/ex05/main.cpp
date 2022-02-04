#include "Karen.hpp"

int main()
{
    Karen a;
    a.complain("debug");
    std::cout << std::endl;

    a.complain("warning");
    std::cout << std::endl;

    a.complain("error");
    std::cout << std::endl;

    a.complain("info");
    std::cout << std::endl;
}