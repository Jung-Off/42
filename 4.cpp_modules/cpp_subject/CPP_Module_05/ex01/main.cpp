#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat bbb("bbb", 15);    
    {
        std::cout << "signed Grade under 150 [form]" << std::endl;
        std::cout << "=================================" << std::endl;
        try
        {
            Form a("aaa", 151, 3);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "=================================" << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "execute Grade under 150 [form]" << std::endl;
        std::cout << "=================================" << std::endl;
        try
        {
            Form a("aaa", 3, 151);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "=================================" << std::endl;
        std::cout << std::endl;
    }


    {
        std::cout << "signed Grade over 1 [form]" << std::endl;
        std::cout << "=================================" << std::endl;
        try
        {
            Form a("aaa", 0, 3);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "=================================" << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "execute Grade over 1 [form]" << std::endl;
        std::cout << "=================================" << std::endl;
        try
        {
            Form a("aaa", 3, 0);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "=================================" << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "sign aviable[form]" << std::endl;
        std::cout << "=================================" << std::endl;
        Form a("aaa", 20, 30);
        try
        {
            std::cout << a << std::endl;
            std::cout << bbb << std::endl;
            bbb.signForm(a);
            std::cout << a << std::endl;
            std::cout << bbb << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "=================================" << std::endl;
    std::cout << std::endl;

    {
        std::cout << "sign unaviable[form]" << std::endl;
        std::cout << "=================================" << std::endl;
        Form a("aaa", 5, 30);
        try
        {
            std::cout << a << std::endl;
            std::cout << bbb << std::endl;
            bbb.signForm(a);
            std::cout << a << std::endl;
            std::cout << bbb << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "=================================" << std::endl;
    std::cout << std::endl;

}