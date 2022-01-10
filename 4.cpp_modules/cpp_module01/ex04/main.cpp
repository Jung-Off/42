#include "main.hpp"

int err_check(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << RED << "The number of factors doesn't match." << RESET << std::endl;
        return (1);
    }
    else if (std::strlen(av[1]) == 0 || std::strlen(av[2]) == 0 || std::strlen(av[3]) == 0)
    {
        if (std::strlen(av[1]) == 0)
            std::cerr << RED << "The first factor is empty!" << RESET << std::endl;
        else if (std::strlen(av[2]) == 0)
            std::cerr << RED << "The Second factor is empty!" << RESET << std::endl;
        else if (std::strlen(av[3]) == 0)
            std::cerr << RED << "The Third factor is empty!" << RESET << std::endl;
        return (1);
    }
    return (0);
}

Transform::Transform(std::string file, std::string before, std::string after)
    : _file(file), _before(before), _after(after)
    {
        std::cout << "Transform Start" << std::endl;
        std::cout << "[" << GREEN << _before << RESET << "] --> " <<
        "[" << GREEN << _after << RESET << "]" << std::endl;
    };

Transform::~Transform()
    {
        std::cout << "Tranformation End" << std::endl;
    }

std::string Transform::get_file()
{
    return(_file);
}

std::string Transform::get_before()
{
    return(_before);
}

int main(int ac, char *av[])
{
    // ./replace text.txt "ds" "dsa"
    if (err_check(ac, av))
        return (1);
    std::ifstream fin(av[1]);
    if(!fin)
    {
        std::cerr << RED << "no file exist!" << RED << std::endl;
        exit(100);
    }

    Transform dummy(av[1], av[2], av[3]);
    std::ofstream fout(dummy.get_file() + ".replace");
    std::string temp;

    // 파일에서 그 문장을 찾는 것이 필요할 거 같고

    // 파일에서 문장을 바꾸는 것이 필요할 거 같고

    while (std::getline(fin, temp))
    {

        size_t npos = 0;
        while(temp.find(dummy.get_file(), npos) != std::string::npos)
        {
            temp.erase(npos, std::strlen(av[2]));
            temp.insert(npos, av[3]);
            npos = temp.find(av[2]);
        }
        fout << temp;
        if (!fin.eof())
            fout << std::endl;
    }

    fin.close();
    fout.close();
    return 0;
}