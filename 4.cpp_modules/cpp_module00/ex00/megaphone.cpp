
#include <iostream>

//표준입력에 접근하기 위해 c++ 스타일을 사용하세요!
//std::cout 시용하기

int main(int ac, char *av[])
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; i < ac; ++i)
    {
        for (int j = 0; av[i][j]; ++j)
            std::cout << static_cast<char>(toupper(av[i][j]));
        std::cout << " ";
    }
    std::cout << std::endl;
}
