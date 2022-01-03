
#include <iostream>
#include "phonebook.hpp"



int main()
{
    PhoneBook book;
    std::string str;

    while(1)
    {
        std::cout << "plz enter command : ";
        std::cin >> str;
        book.cmd = str;
        switch (book.check_cmd(str))
        {
        case 1:
            book.add(); 
        case 2:
            book.search(); 
        
            /* code */
            break;
        
        default:
            break;
        }
    }
    


}