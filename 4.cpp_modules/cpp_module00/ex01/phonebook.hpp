
#include <iostream>

class PhoneBook {
    private:
    int _index;
    char *_firstname;
    char *_lastname;
    char *_nickname;

    public:
        std::string cmd;
        int check_cmd(std::string str);
        void add(void);
};

int PhoneBook::check_cmd(std::string str)
{
    if (cmd.compare(0, 3, str))
        return 1;
    else if (cmd.compare(0, 4, str))
        return 2;
    else if (cmd.compare(0, 6, str))
        return 3;
    else
        return 0;    
}

void PhoneBook::add(void)
{
    std::cout << "hello\n" << std::endl;
}