#include <iostream>
#include <cstring>
using namespace std;

class SoSimple
{
    private:
        int _num;
    public:
        SoSimple(int n) : _num(n)
        {
            cout << "num = " << _num << ", ";
            cout << "address = " << this << endl;
        }
        void ShowSimpleData()
        {
            cout << _num << endl;
        }
        SoSimple* GetThisPointer()
        {
            return this;
        }
};

int main()
{
    SoSimple sim1(100);
    SoSimple *ptr1 = sim1.GetThisPointer(); // sim1객체의 주소값 저장
    cout << ptr1 << ", ";
    ptr1->ShowSimpleData();

    SoSimple sim2(200);

    SoSimple *ptr2 = sim2.GetThisPointer(); //sim2객체의 주소값 저장
    cout << ptr2 << ", ";
    ptr2->ShowSimpleData();
}