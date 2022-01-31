
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
    private:
        std::string _firstname;
        std::string _name;
        std::string _nickname;
        std::string _phonenum;
        std::string _secert;
    public:
        void SetFirstName(std::string firstname);
        void SetName(std::string name);
        void SetNickName(std::string nickname);
        void SetPhone(std::string phonenum);
        void SetSecert(std::string secert);
        Contact();
        ~Contact();
        // std::string GetFirstName();
        // std::string GetName();
        // std::string GetNickName();
        // std::string GetPhone();
        // std::string GetSecert();
};

#endif

