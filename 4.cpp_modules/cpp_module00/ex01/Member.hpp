#ifndef MEMBER_HPP
# define MEMBER_HPP

#include <iostream>

class Member {
    private:
        std::string     _FirstName;
        std::string     _LastName;
        std::string     _NickName;
        std::string     _Number;
        std::string     _DarkSecret;

    public:
        void            set_fname(std::string str);
        void            set_lname(std::string str);
        void            set_Nname(std::string str);
        void            set_Num(std::string str);
        void            set_Secret(std::string str);
        std::string     get_fname();
        std::string     get_lname();
        std::string     get_Nname();
        std::string     get_Num();
        std::string     get_Secret();
};

#endif