#include <iostream>

using namespace std;

class MyFriendInfo
{
    private:
        char *name;
        int age;
    public:
        MyFriendInfo(char *fname, int age)
            : age(age)
        {
            std::cout << "MyFriendInfo(char *fname, int age)" << std::endl;
            name = new char [strlen(fname)];
            strcpy(name, fname);
        }
        ~MyFriendInfo()
        {
            std::cout << "~MyFriendInfo" << std::endl;
            delete []name;
        }
        void ShowMyFriendInfo()
        {
            cout << "이름 : " << name << endl;
            cout << "나이 : " << age << endl;
        }
};

class MyFriendDetailInfo : public MyFriendInfo
{
    private:
        char *addr;
        char *phone;
    public:
        void ShowMyfriendDetailInfo()
        {
            ShowMyFriendInfo();
            cout << "주소 : " << addr << endl;
            cout << "전화 : " << phone << endl << endl;
        }
        MyFriendDetailInfo(char *faddr, char *fphone, char *name, int age)
            :   MyFriendInfo(name, age)
        {
            std::cout << "MyFriendDetailInfo(char *faddr, char *fphone, char *name, int age)" << std::endl;
            addr = new char[strlen(faddr)];
            strcpy(addr, faddr);
            phone = new char[strlen(fphone)];
            strcpy(phone, fphone);
        }
        ~MyFriendDetailInfo()
        {
            std::cout <<  "~MyFriendDetailInfo()" << std::endl;
            delete []addr;
            delete []phone;
        }
};

int main()
{
    MyFriendInfo mfi("you", 4);
    mfi.ShowMyFriendInfo();

    std::cout << std::endl;
    MyFriendDetailInfo mfdi("swu", " 010", "arr", 6);
    mfdi.ShowMyfriendDetailInfo();

}