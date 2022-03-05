#include "Bureaucrat.hpp"

int main()
{
    std::cout << "Constructor Test" << std::endl;
    try
    {
        Bureaucrat ex("x", 151);
        //여기 아래는 exception 으로 처리됨
        Bureaucrat a("x", -1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    std::cout << "Inc Test" << std::endl;
    try
    {
        Bureaucrat b("bob", 5);
        std::cout << b << std::endl;

        b.gradeHigher(3);
        std::cout << b << std::endl;
        b.gradeHigher(3);
        std::cout << b << std::endl;
        //여기 아래도 수행이 안됨
        b.gradeHigher(3);
        std::cout << b << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "Dec test" << std::endl;
    try
    {
        Bureaucrat a("ant", 145);
        std::cout << a << std::endl;

        a.gradeLower(1);
        std::cout << a << std::endl;
        a.gradeLower(6);
        std::cout << a << std::endl;
        //여기 아래도 수행이 안됨
        a.gradeLower(6);
        std::cout << a << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }   
}