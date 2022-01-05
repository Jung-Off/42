
#include "Phonebook.hpp"

int main()
{
    PhoneBook book;
    std::string new_cmd;

    while(1)
    {
        book.pb_intro();
        std::getline(std::cin, new_cmd);
        if (std::cin.eof())
            exit(1);
        book.set_cmd(new_cmd);
        if (book.get_cmd() == "ADD")
            book.add();
        else if (book.get_cmd() == "SEARCH")
            book.search();
        else if (book.get_cmd() == "EXIT")
        {
            std::cout << YELLOW << "SEE YOU LATER..."<< RESET << std::endl;
            return (0);
        }
        else
        {
            std::cout << RED << book.get_cmd() + " is not command!" << std::endl;
            std::cout << "ARE YOU FOOL??????" << RESET << std::endl;
            std::cout << "Enter the command below!!!!" << std::endl;
        }
    }
} 