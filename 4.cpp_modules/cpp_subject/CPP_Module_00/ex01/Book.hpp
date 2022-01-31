#ifndef BOOK_HPP
# define BOOK_HPP

#include <iostream>

namespace PHONEBOOK
{
    std::string Command[3] = {"ADD", "SEARCH", "EXIT"};

    void print_command()
    {
        std::cout << std::endl;
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

#endif