#include "Contact.hpp"

void Contact::SetFirstName(std::string firstname)
{
    _firstname = firstname;
}

void Contact::SetName(std::string name)
{
    _name = name;
}

void Contact::SetNickName(std::string nickname)
{
    _nickname = nickname;
}

void Contact::SetPhone(std::string phonenum)
{
    _phonenum = phonenum;
}

void Contact::SetSecert(std::string secert)
{
    _secert = secert;
}

Contact::Contact()
{
    std::cout << "make Contact" << std::endl;
}

Contact::~Contact()
{
    std::cout << "break Contact" << std::endl;
}