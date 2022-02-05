#include "Karen.hpp"

int main()
{
    Karen a;
    a.complain("DEBUG");
    std::cout << std::endl;

    a.complain("WARNING");
    std::cout << std::endl;

    a.complain("INFO");
    std::cout << std::endl;

    a.complain("ERROR");
    std::cout << std::endl;
}