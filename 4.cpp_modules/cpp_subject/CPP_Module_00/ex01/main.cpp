
#include "PhoneBook.hpp"
#include "Book.hpp"

int main()
{
    Phonebook book;
    std::string cmd;
    while (true)
    {
        PHONEBOOK::print_command();
        std::cout << "Command Line input : ";
        cmd = book.command_upper(book.Input());
        if (cmd == PHONEBOOK::Command[0])
            book.add();
        else if (cmd == PHONEBOOK::Command[1])
            book.search();
        else if (cmd == PHONEBOOK::Command[2])
            break;
        else
            PHONEBOOK::print_err(cmd);
    }
    PHONEBOOK::print_exit();
    return (0);
}