
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#define MAX_CONTACT 8

class Phonebook
{
    private:
        Contact _person[MAX_CONTACT];
    public:
        Phonebook();
        ~Phonebook();
        
        void add();
        void search();
        std::string Input();
        std::string command_upper(std::string cmd);
};

#endif
