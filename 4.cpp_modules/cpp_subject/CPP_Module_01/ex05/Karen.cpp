#include "Karen.hpp"

void Karen::_debug()
{
    std::cout << BLUE << "DEBUG" << RESET << std::endl;
    std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
    std::cout <<"I just love it!" << std::endl;
}

void Karen::_info()
{
    std::cout << GREEN << "INFO" << RESET << std::endl;
    std::cout << "I cannot believe adding extra bacon cost more money. " << std::endl;
    std::cout << "You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Karen::_warning()
{
    std::cout << RED << "WARNING" << RESET << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Karen::_error()
{
    std::cout << YELLOW << "ERROR" << RESET << std::endl;
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

Karen::Karen()
{
    std::cout << "Birth Karen 2.0" << std::endl;
    _f[0] = &Karen::_debug;
    _f[1] = &Karen::_info;
    _f[2] = &Karen::_warning;
    _f[3] = &Karen::_error;
}

Karen::~Karen()
{
    std::cout << "Death Karen 2.0" << std::endl;
}

void Karen::complain(std::string level)
{
    std::string temp[4] = { "debug", "info", "warning", "error" };

    for(int i = 0; i < 4; i++)
    {
        if(level == temp[i])
        {
            (this->*_f[i])();
            return ;
        }
    }
}