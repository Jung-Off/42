#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    private:
        char *name;
    public:
        Person(char * myname)
        {
            name = new char[strlen(myname) + 1];
            strcpy(name, myname);
        }
        ~Person()
        {
            delete []name;
        }
        void WhatYourName() const
        {
            cout << "My name is " << name << endl;
        }
};

class UnivStudent : public Person
{
    private:
        char *major; //전공 과목
    public:
        UnivStudent(char* myname, char* mymajor)
            :   Person(myname)
        {
            major = new char[strlen(mymajor) + 1];
            strcpy(major, mymajor);
        }
        ~UnivStudent()
        {
            delete []major;
        }
        void WhoAreYou() const
        {
            WhatYourName();
            cout << "My major is " << major << endl << endl;
        }
};

int main()
{
    UnivStudent ustd1("Lee", "Computer eng. ");
    ustd1.WhoAreYou();

    UnivStudent ustd2("Yoon", "Electronic eng. ");
    ustd2.WhoAreYou();
    return 0;
}