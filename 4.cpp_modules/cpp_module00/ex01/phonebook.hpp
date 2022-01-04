
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <stdio.h>
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

class PhoneBook {
    private:
        int            _index;
        Member         _M[8];
        std::string    _cmd;

    public:
        void            pb_intro(void) const;
        void            set_cmd(std::string new_cmd);
        std::string     get_cmd(void) const;
        void            add(void);
        void            set_index(const int i);
        int             get_index(void) const;
        void            increase_index();
        void            search(void);

        PhoneBook();
        ~PhoneBook();
};

#endif