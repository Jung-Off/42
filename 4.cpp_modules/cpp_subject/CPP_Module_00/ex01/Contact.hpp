
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
        std::string GetFirstName() const;
        std::string GetName() const;
        std::string GetNickName() const;
        std::string GetPhone() const;
        std::string GetSecert() const;
        Contact();
        ~Contact();
};

#endif

