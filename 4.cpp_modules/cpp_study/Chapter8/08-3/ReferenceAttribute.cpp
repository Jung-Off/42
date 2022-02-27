#include <iostream>
using namespace std;

class First
{
    public:
        void FirstFunc() { cout << "FirstFunc()" << endl; }
        virtual void SimpleFunc() { cout << " First's SimpleFunc()" << endl; }
};

class Second : public First
{
    public:
        void SecondFunc() { cout << "SecondFunc()" << endl; }
        virtual void SimpleFunc() { cout << " Second's SimpleFunc()" << endl; }
};

class Third : public Second
{
    public:
        void ThirdFunc() { cout << "ThirdFunc()" << endl; }
        virtual void SimpleFunc() { cout << " Third's SimpleFunc()" << endl; }
};

int main()
{
    Third obj;
    obj.FirstFunc();    //1
    obj.SecondFunc();   //2
    obj.ThirdFunc();    //3
    obj.SimpleFunc();   //3

    Second & sref = obj;
    sref.FirstFunc();   //1
    sref.SecondFunc();  //2
    sref.SimpleFunc();  //3

    First & fref = obj;
    sref.FirstFunc();   //1
    sref.SimpleFunc();  //3
}