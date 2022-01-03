
#include <iostream>


class PhoneBook {
    private:
    int _index;
    char *_firstname;
    char *_lastname;
    char *_nickname;

    public:
        void PhoneBook_Add(int index);
        void print();
};

void PhoneBook::PhoneBook_Add(int index)
{
    _index = index;
}

void PhoneBook::print()
{
    std::cout << _index << std::endl;
}

int main()
{
    PhoneBook pb;
    char *str;

    while(1)
    {
        std::cout << "plz enter command : ";
        std::cin >> str;
        switch (str)
        {
        case str == "EXIT":
            /* code */
            break;
        
        default:
            break;
        }
    }
    


}