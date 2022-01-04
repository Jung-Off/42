#include "Member.hpp"

void Member::set_fname(std::string firstname)
{
    _FirstName = firstname;
}

void Member::set_lname(std::string lastname)
{
    _LastName = lastname;
}

void Member::set_Nname(std::string nickname)
{
    _NickName = nickname;
}

void Member::set_Num(std::string num)
{
    _Number = num;
}

void Member::set_Secret(std::string secret)
{
    _DarkSecret = secret;
}

std::string Member::get_fname()
{
    return(_FirstName);
}

std::string Member::get_lname()
{
    return(_LastName);
}

std::string Member::get_Nname()
{
    return(_NickName);
}

std::string Member::get_Num()
{
    return(_Number);
}

std::string Member::get_Secret()
{
    return(_DarkSecret);
}