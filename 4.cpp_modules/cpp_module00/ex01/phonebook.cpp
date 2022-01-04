
#include "Phonebook.hpp"

void PhoneBook::pb_intro(void) const
{
    std::cout << "1. ADD" << std::endl;
    std::cout << "2. SEARCH" << std::endl;
    std::cout << "3. EXIT" << std::endl;
    std::cout << GREEN << "Plz what you want using command!" << RESET << std::endl;
    std::cout << "What's the command? : " ;
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

void PhoneBook::increase_index()
{
    ++_index;
}

void PhoneBook::add(void)
{
    std::cout << "ADD" << std::endl;
    if (_index >= 8)
        set_index(0);
    increase_index();
    _M[_index].set_idx(get_index());

    std::string temp;

    std::cout << "WHAT YOUR FIRST NAME ? : ";
    std::getline(std::cin, temp);
    _M[_index].set_fname(temp);

    std::cout << "WHAT YOUR LAST NAME ? : ";
    std::getline(std::cin, temp);
    _M[_index].set_lname(temp);

    std::cout << "WHAT YOUR NICK NAME ? : ";
    std::getline(std::cin, temp);
    _M[_index].set_Nname(temp);


    std::cout << "WHAT YOUR PHONE NUMBER ? : ";
    std::getline(std::cin, temp);
    _M[_index].set_Num(temp);


    std::cout << "WHAT YOUR SECRET ? : ";
    std::getline(std::cin, temp);
    _M[_index].set_Secret(temp);

}

void PhoneBook::search(void)
{
    std::cout << "SEARCH" << std::endl;
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

        for (int i = 1; i <= _index; ++i)
        std::cout << std::setw(WIDTH) << _M[i].get_idx() << "|"
        << std::setw(WIDTH) <<  _M[i].get_fname() << "|"
        << std::setw(WIDTH) <<  _M[i].get_lname() << "|"
        << std::setw(WIDTH) <<  _M[i].get_Nname() << "|"
        << std::setw(WIDTH) <<  _M[i].get_Num() << std::endl;
        //SEARCH만 했을때
        //SEARCH index만 했을때
    }

    std::string new_cmd;
    std::getline(std::cin, new_cmd);
    


}

PhoneBook::PhoneBook() : _index(0)
{
    std::cout << BLUE << "OPEN! MY PHONBOOK! "<< RESET << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << BLUE << "Bye Bye~~"<< RESET << std::endl;
}
