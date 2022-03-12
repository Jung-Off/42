#include "Array.hpp"

int main()
{
    std::cout << "int arrary " << std::endl;
    try
    {
        unsigned int i;
        Array<int> a_int(5);
        for (i = 0; i < a_int.size(); i++)
        {
            a_int[i] = i;
            std::cout << a_int[i] << " ";
        }
        std::cout << std::endl;
        
        std::cout << a_int[i] << " ";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    std::cout << "char arrary " << std::endl;
    try
    {
        unsigned int i;
        char    alpabet[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
        Array<char> a_char(7);

        for (i = 0; i < a_char.size(); i++)
        {
            a_char[i] = alpabet[i];
            std::cout << a_char[i] << " ";
        }
        std::cout << std::endl;
        std::cout << a_char[i] << " ";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    std::cout << "double arrary " << std::endl;
    try
    {
        unsigned int i;
        double      rate[4] = {3.1415, 2.13748, 1.41414, 2.76543};
        Array<double> a_double(5);

        for (i = 0; i < a_double.size(); i++)
        {
            a_double[i] = rate[i];
            std::cout << a_double[i] << " ";
        }
        std::cout << std::endl;
        std::cout << a_double[i] << " ";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    
    std::cout << "string arrary " << std::endl;
    try
    {
        unsigned int i;
        std::string fruits[3] = {"apple", "banana", "egg"};
        Array<std::string> a_string(2);
        for (i = 0; i < a_string.size(); i++)
        {
            a_string[i] = fruits[i];
            std::cout << a_string[i] << " ";
        }
        std::cout << std::endl;
        std::cout << a_string[i] << " ";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}