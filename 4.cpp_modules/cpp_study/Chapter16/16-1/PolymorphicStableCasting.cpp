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
    SoSimple* sptr = new SoSimple;
    SoComplex * cptr = dynamic_cast<SoComplex*>(sptr);
    if(cptr == NULL)
        cout << "형변환 실패" << endl;
    else
        comPtr->ShowSimpleInfo();
    return 0;
}