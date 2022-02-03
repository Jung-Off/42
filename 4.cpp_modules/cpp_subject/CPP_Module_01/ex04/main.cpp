#include "fileref.hpp"

bool replace_file(Data &data)
{
    File file(data, data.getFilename());

    if(!file.ReadOpen())
        return (false);
    if(!file.WriteOpen())
        return (false);
    file.Change();
    file.Close();
    return (true);  
}

int ArgCheck(int ac)
{
    if (ac == 4)
        return (true);
    else if (ac == 1)
        std::cout << "Input File Name" << std::endl;
    else if (ac == 2)
        std::cout << "Input argument" << std::endl;
    else if (ac == 3)
        std::cout << "Input argument string to AFTER" << std::endl;
    else
        std::cout << "argument count is over!" << std::endl;
    return (false);
}

int main(int ac, char *av[])
{
    if (!ArgCheck(ac))
        return (false);
    Data data(av[1], av[2], av[3]);
    if (!replace_file(data))
        return (false);
    return (true);
}