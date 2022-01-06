
#include <iostream>

//std::cout 사용하기

//version 1

// int main(int ac, char *av[])
// {
//     if (ac == 1)
//         std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
//     for (int i = 1; i < ac; ++i)
//     {
//         for (int j = 0; av[i][j]; ++j)
//             std::cout << static_cast<char>(toupper(av[i][j]));
//         std::cout << " ";
//     }
//     std::cout << std::endl;
// }

//version 2

std::string to_upper(std::string cmd)
{
    for (size_t i = 0; i < cmd.size(); i++)
        cmd[i] = std::toupper(cmd[i]);
    return cmd;
}

int main(int ac, char *av[])
{
    std::string cmd;
    if (ac == 1)
    {
      cmd = "* LOUD AND UNBEARABLE FEEDBACK NOISE *"; //char* > string으로 캐스팅
      std::cout << cmd;
    }
    for (int i = 1; i < ac; ++i)
    {
        cmd = to_upper(av[i]); //char* > string으로 캐스팅
        std::cout << cmd;
    }
    std::cout << std::endl;
}
