
#include "PhoneBook.hpp"

Phonebook::Phonebook()
    : _index(0)
{
    std::cout << std::endl;
    std::cout << "Welcome Phonebook!" << std::endl;
}

Phonebook::~Phonebook()
{
    std::cout << std::endl;
    std::cout << "Close Phoenbook!" << std::endl;
}

std::string Input()
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
    int curr;

    curr = _index % MAX_CONTACT;
    std::cout << "what your first name ? ";

    _person[curr].SetFirstName(Input());

    std::cout << "what your name ? ";
    _person[curr].SetName(Input());

    std::cout << "what your nick name ? ";
    _person[curr].SetNickName(Input());
    
    std::cout << "what your Phone number ? ";
    _person[curr].SetPhone(Input());

    std::cout << "what your Seceret ? ";
    _person[curr].SetSecert(Input());
    
    _index++;
}

std::string Phonebook::str_10(std::string data)
{
    if(data.length() > 10)
    {
        data[9] = '.';
        data.erase(10);
    }
    return (data);
}

void Phonebook::search()
{
    // std::cout << "search" << std::endl;

    if (_index == 0)
    {
        std::cout << "empty!" << std::endl;
        return ;
    }

    std::cout << std::setw(10) << "Index" <<
        '|' << std::setw(10) << "FirstName" <<
        '|' << std::setw(10) << "Name" <<
        '|' << std::setw(10) << "NickName" <<
        '|' << std::setw(10) << "Phone" << std::endl;

    for (int i = 0; i < COMPARE(MAX_CONTACT, _index); ++i)
    {
        std::cout << std::setw(10) << i + 1 <<
            '|' << std::setw(10) << str_10(_person[i].GetFirstName()) <<
            '|' << std::setw(10) << str_10(_person[i].GetName()) <<
            '|' << std::setw(10) << str_10(_person[i].GetNickName()) <<
            '|' << std::setw(10) << str_10(_person[i].GetPhone()) << std::endl;
    }

    while (1)
    {
        std::cout << "what number do you want ? ";
        int search = 0;
        std::stringstream stoi(Input());
        stoi >> search;
        if (search >= 1 && search <= COMPARE(MAX_INPUT, _index))
        {
            std::cout << "INDEX : " << search << std::endl;
            std::cout << "FirstName : " << _person[search - 1].GetFirstName() << std::endl;
            std::cout << "Name : " << _person[search - 1].GetName() << std::endl;
            std::cout << "NickName : " << _person[search - 1].GetNickName() << std::endl;
            std::cout << "Phone : " << _person[search - 1].GetPhone() << std::endl;
            std::cout << "Secert : " << _person[search - 1].GetSecert() << std::endl;
            break;
        }
        else
            std::cout << "plz boundary number" << std::endl;
    }
}