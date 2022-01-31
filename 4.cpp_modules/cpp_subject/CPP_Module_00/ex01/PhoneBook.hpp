
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <sstream>

#define MAX_CONTACT 8

#define COMPARE(a, b) ( a > b ? b : a )

class Phonebook
{
    private:
        Contact _person[MAX_CONTACT];
        int     _index;
    public:
        Phonebook();
        ~Phonebook();
        
        void add();
        void search();
        std::string command_upper(std::string cmd);
        std::string str_10(std::string data);
};

std::string Input();

#endif
