#include <iostream>
using namespace std;

class SoSimple      //Polymorphic 클래스
{
    public:
        virtual void ShowSimpleInfo()
        {
            cout << "SoSimple Base Class" << endl;
        }
};

class SoComplex : public SoSimple
{
    public:
        void ShowSimpleInfo()
        {
            cout << "SoComplex Derived Class " << endl;
        }
};

int main()
{
    SoSimple* sptr = new SoComplex;
    SoComplex * cptr = dynamic_cast<SoComplex*>(sptr);
    cptr->ShowSimpleInfo();
}