#include "fileref.hpp"

File::File(Data &data, std::string str)
    : _data(data), _writeFileName(str)
    {
        std::cout << "Change" << "[" << GREEN << _data.getFilename() << RESET << "]" << std::endl;
    std::cout << "[" << RED << _data.getBefore() << RESET << "] -> [" << BLUE << _data.getAfter() << RESET << "]" << std::endl
     << std::endl;
    };
    
bool File::ReadOpen()
{
    _readFile.open(_data.getFilename());
    if (!_readFile.is_open())
    {
        std::cout << "[" << _data.getFilename() << "]" << "does not open" << std::endl;
        return (false);
    }
    std::cout << "[" << _data.getFilename() << "]" << " OPEN !!" << std::endl;
    return (true);
}

bool File::WriteOpen()
{
    _writeFileName += ".replace";
    _writeFile.open(_writeFileName);
    if (!_writeFile.is_open())
    {
        std::cout << "[" << _writeFileName << "]" << " is not open !!" << std::endl << std::endl;
        return (false);
    }
    std::cout << "[" << _writeFileName << "]" << " OPEN !!" << std::endl << std::endl;
    return (true);
}

void File::Change()
{
    while(!_readFile.eof())
    {
        std::string readline;
        std::getline(_readFile, readline);
        int findpos = 0, temp;
        while((temp = (int)readline.find(_data.getBefore(), findpos)) != -1)
        {
            readline.erase(temp, _data.getBefore().size());
            readline.insert(temp, _data.getAfter());
            findpos = temp + _data.getAfter().size();
        }
        _writeFile << readline; 
        if(!_readFile.eof()) //마지막 줄에 있어서는 입력하면 안됨
            _writeFile << std::endl; 
    }
}

void File::Close()
{
    _readFile.close();
    std::cout << "[" << _data.getFilename() << "]" << " CLOSE !!" << std::endl;
    _writeFile.close();
    std::cout << "[" << _writeFileName << "]" << " CLOSE !!" << std::endl << std::endl;
}

File::~File()
{
    std::cout << "Change Complete! " << std::endl;
}




