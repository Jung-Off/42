#include <iostream>

void print_upper(std::string temp)
{
    for (size_t i = 0; i < temp.length(); ++i)
        temp[i] = std::toupper(temp[i]);
    std::cout << temp;
}

int main(int ac, char *av[])
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < ac; i++)
            print_upper(av[i]);
        std::cout << std::endl;
    }
    return 0;
}