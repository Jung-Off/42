
#include "iter.hpp"

int main()
{
    int         age[10] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
    char        alpabet[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    double      rate[4] = {3.1415, 2.13748, 1.41414, 2.76543};
    std::string fruits[3] = {"apple", "banana", "egg"};

    std::cout << "int : ";
    iter(age, sizeof(age) / sizeof(*age), print);

    std::cout << "char : ";
    iter(alpabet, sizeof(alpabet) / sizeof(*alpabet), print);

    std::cout << "double : ";
    iter(rate, sizeof(rate) / sizeof(*rate), print);

    std::cout << "string : ";
    iter(fruits, sizeof(fruits) / sizeof(*fruits), print);
    
}