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

std::string Contact::GetFirstName() const
{
    return (_firstname);
}

std::string Contact::GetName() const
{
    return (_name);
}

std::string Contact::GetNickName() const
{
    return (_nickname);
}

std::string Contact::GetPhone() const
{
    return (_phonenum);
}

std::string Contact::GetSecert() const
{
    return (_secert);
}

Contact::Contact()
{
    // std::cout << "make Contact" << std::endl;
}

Contact::~Contact()
{
    // std::cout << "break Contact" << std::endl;
}