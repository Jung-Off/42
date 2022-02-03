#include "data.hpp"

Data::Data(std::string file, std::string before, std::string after)
    : _FileName(file), _Before(before), _After(after)
{
    std::cout << "Data create" << std::endl << std::endl;
}

std::string Data::getFilename(void) const
{
    return (_FileName);
}

std::string Data::getBefore(void) const
{
    return (_Before);
}

std::string Data::getAfter(void) const
{
    return (_After);
}

Data::~Data()
{
    std::cout << "Data is end" << std::endl;
}