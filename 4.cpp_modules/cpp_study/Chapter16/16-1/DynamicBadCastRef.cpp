#include <iostream>
using namespace std;

class SoSimple
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
            cout << "SoComplex Derived Class" << endl;
        }
};

int main()
{
    SoSimple simobj;
    SoSimple& ref = simobj;

    try
    {
        SoComplex& cref = dynamic_cast<SoComplex&>(ref);
        cref.ShowSimpleInfo();
    }
    catch(bad_cast e)
    {
        std::cerr << e.what() << '\n';
    }
    
}