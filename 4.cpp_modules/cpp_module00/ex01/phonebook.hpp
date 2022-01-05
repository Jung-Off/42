
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include "Member.hpp"

#define RED 	"\x1b[31m"
#define GREEN 	"\x1b[32m"
#define YELLOW 	"\x1b[33m"
#define BLUE 	"\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN	"\x1b[36m"
#define RESET 	"\x1b[0m"

#define CMD_ADD     1
#define CMD_SEARCH  2
#define CMD_EXIT    3

#define WIDTH       10

class PhoneBook {
    private:
        int            _index;
        int            _size;
        Member         _M[8];
        std::string    _cmd;

    public:
        void            pb_intro(void) const;
        void            set_cmd(std::string new_cmd);
        std::string     get_cmd(void) const;
        void            set_index(const int i);
        int             get_index(void) const;
        void            increase_index();
        void            set_size(const int i);
        int             get_size(void) const;
        void            increase_size();
        void            add(void);
        void            search(void);
        std::string     print_width(std::string str) const;

        PhoneBook();
        ~PhoneBook();
};

#endif