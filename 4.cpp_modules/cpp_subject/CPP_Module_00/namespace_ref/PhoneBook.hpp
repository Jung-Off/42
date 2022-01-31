
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#define MAX_CONTACT 8

namespace PHONEBOOK
{
    // const int MAX_CONTACT = 8;
    std::string Command[3] = {"ADD", "SEARCH", "EXIT"};

    void print_command()
    {
        std::cout << "1. ADD" << std::endl;
        std::cout << "2. SEARCH" << std::endl;
        std::cout << "3. EXIT" << std::endl;
    }

    void print_err(std::string cmd)
    {  
        std::cout << cmd << " This command does not exist."
                        << std::endl;   
    }

    void print_exit()
    {
        std::cout << "Bye Bye!" << std::endl;
    }
}

class Phonebook
{
    private:
        Contact _person[MAX_CONTACT];
    public:
        Phonebook();
        ~Phonebook();
        void add();
        void search();
};

#endif
