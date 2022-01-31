
#include "PhoneBook.hpp"

Phonebook::Phonebook()
{
    std::cout << std::endl;
    std::cout << "Welcome Phonebook!" << std::endl;
    std::cout << std::endl;
}

Phonebook::~Phonebook()
{
    std::cout << std::endl;
    std::cout << "Close Phoenbook!" << std::endl;
}

std::string Phonebook::Input()
{
    std::string cmd;
    std::getline(std::cin, cmd);
    if (std::cin.eof())
        exit(1);
    return (cmd);
}

std::string Phonebook::command_upper(std::string cmd)
{
    for (size_t i = 0; i < cmd.length(); ++i)
        cmd[i] = std::toupper(cmd[i]);
    return (cmd);
}

void Phonebook::add()
{
    std::cout << "add" << std::endl;
}

void Phonebook::search()
{
    std::cout << "search" << std::endl;
}