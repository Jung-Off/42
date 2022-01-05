
#include "Phonebook.hpp"

void PhoneBook::pb_intro(void) const
{
    std::cout << "1. ADD" << std::endl;
    std::cout << "2. SEARCH" << std::endl;
    std::cout << "3. EXIT" << std::endl;
    std::cout << GREEN << "Plz what you want using command!" << RESET << std::endl;
    std::cout << YELLOW << "What's the command? : " << RESET;
}

void PhoneBook::set_cmd(std::string new_cmd)
{
    for (size_t i = 0; i < new_cmd.size(); ++i)
        new_cmd[i] = toupper(new_cmd[i]);
        _cmd = new_cmd;
}

std::string PhoneBook::get_cmd() const
{
    return(_cmd);
}

void PhoneBook::set_index(const int i)
{
    _index = i;
}

int PhoneBook::get_index(void) const
{
    return(_index);
}

void PhoneBook::set_size(const int i)
{
    _index = i;
}

int PhoneBook::get_size(void) const
{
    return(_size);
}

void PhoneBook::increase_size()
{
    ++_size;
}

void PhoneBook::increase_index()
{
    ++_index;
}

void PhoneBook::add(void)
{
    if (_index == 8)
        set_index(0);
    _M[_index].set_idx(get_index());

    // std::cout << "phonebook : " << get_index() << std::endl;        //arr index
    // std::cout << "member : " << _M[_index].get_idx() << std::endl;  //phone book index

    std::string temp;

    std::cout << std::endl;
    std::cout << YELLOW << "WHAT YOUR FIRST NAME ? : " << RESET;
    std::getline(std::cin, temp);
    _M[_index].set_fname(temp);

    std::cout << YELLOW << "WHAT YOUR LAST NAME ? : " << RESET;
    std::getline(std::cin, temp);
    _M[_index].set_lname(temp);

    std::cout << YELLOW << "WHAT YOUR NICK NAME ? : " << RESET;
    std::getline(std::cin, temp);
    _M[_index].set_Nname(temp);


    std::cout << YELLOW << "WHAT YOUR PHONE NUMBER ? : " << RESET;
    std::getline(std::cin, temp);
    _M[_index].set_Num(temp);

    std::cout << YELLOW << "WHAT YOUR SECRET ? : " << RESET;
    std::getline(std::cin, temp);
    _M[_index].set_Secret(temp);

    increase_index();
    if (_size < 8)
        increase_size();
}

std::string PhoneBook::print_width(std::string str) const
{
    std::string temp = str;

    if (temp.size() > 10)
    {
        temp[9] = '.';
        temp.erase(10);
    }
    return (temp);
}

void PhoneBook::search(void)
{
    if (_index == 0)
    {
        std::cout << RED << "Phonebook is empty :(" << RESET << std::endl;
        return ;
    }
    else
    {
        std::cout << std::setw(WIDTH) << "index" << "|" <<
        std::setw(WIDTH) << "firstname" << "|" <<
        std::setw(WIDTH) << "lastname" << "|" <<
        std::setw(WIDTH) << "nickname" << "|" <<
        std::setw(WIDTH) << "number" << std::endl;
    
        for (int i = 0; i < get_size(); ++i)
        std::cout << std::setw(WIDTH) << _M[i].get_idx() << "|"
        << std::setw(WIDTH) <<  print_width(_M[i].get_fname()) << "|"
        << std::setw(WIDTH) <<  print_width(_M[i].get_lname()) << "|"
        << std::setw(WIDTH) <<  print_width(_M[i].get_Nname()) << "|"
        << std::setw(WIDTH) <<  print_width(_M[i].get_Num()) << std::endl;
    }

    int search_i;
    std::string new_cmd;

    while(1)
    {
        std::cout << YELLOW << "Which Index Do You Want ?: " << RESET;
        std::getline(std::cin, new_cmd);
        if (std::cin.eof())
            exit(1);
        std::stringstream StringToInt(new_cmd);

        StringToInt >> search_i;

        if (search_i <= 0 || search_i > _index)
        {
            std::cout << RED << "Out Of Range or Nothing stored in that index" <<
            RESET << std::endl;
        }
        else
        {
            std::cout << std::endl;
            std::cout << "REQUSET" << std::endl;
            std::cout << "Index : " << _M[search_i - 1].get_idx() << std::endl; 
            std::cout << "First Name : " << _M[search_i - 1].get_fname() << std::endl;
            std::cout << "Last Name : " << _M[search_i - 1].get_lname() << std::endl;
            std::cout << "Nick Name : " << _M[search_i - 1].get_Nname() << std::endl;
            std::cout << "Phone Num : " << _M[search_i - 1].get_Num() << std::endl;
            std::cout << "Darkset Secret : " << _M[search_i - 1].get_Secret() << std::endl;
            std::cout << std::endl;
            return ;
        }
    }
}

PhoneBook::PhoneBook() : _index(0), _size(0)
{
    std::cout << BLUE << "OPEN! MY PHONBOOK! "<< RESET << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << BLUE << "Bye Bye~~"<< RESET << std::endl;
}
