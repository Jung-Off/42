
#include <iostream>

class Printer
{
    private:
        char* _str;
        //char _str[30];
    public:
        void ShowString();
        void SetString(char *str);
};

void Printer::ShowString()
{
    std::cout << "[" << _str << "]" << std::endl;
}

void Printer::SetString(char *str)
{
    _str = str;
    //strcpy(_str, str);
    return ;
}

int main()
{
    Printer pnt;
    pnt.SetString("Hello world!");
    pnt.ShowString();

    pnt.SetString("I love C++");
    pnt.ShowString();
    return 0;
}