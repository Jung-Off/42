#include "Bureaucrat.hpp"

int main()
{

    {
        std::cout << "create except under 150" << std::endl;
        std::cout << "=================================" << std::endl;
        try
        {
            Bureaucrat z("zzz", 150);
            Bureaucrat a("aaa", 151);
            Bureaucrat b("bbb", 15);    //not execute
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "=================================" << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "create except over 1" << std::endl;
        std::cout << "=================================" << std::endl;
        try
        {
            Bureaucrat c("ccc", 1);
            Bureaucrat d("ddd", 0);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }    
        std::cout << "=================================" << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "increment" << std::endl;
        std::cout << "=================================" << std::endl;
        try
        {
            Bureaucrat a("aaa", 10);
            a.increGrade(5);
            a.increGrade(5);
            a.increGrade(5); //not execute
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }    
        std::cout << "=================================" << std::endl;
        std::cout << std::endl;
    }


    {
        std::cout << "decrement" << std::endl;
        std::cout << "=================================" << std::endl;
        try
        {
            Bureaucrat a("aaa", 130);
            a.decreGrade(10);
            a.decreGrade(10);
            a.decreGrade(1);
            a.decreGrade(10); //not execute
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }    
        std::cout << "=================================" << std::endl;
        std::cout << std::endl;
    }
}