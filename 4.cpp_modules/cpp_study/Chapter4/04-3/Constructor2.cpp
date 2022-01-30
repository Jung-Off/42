#include <iostream>
using namespace std;

class SimpleClass
{
    private:
        int _num1;
        int _num2;
    public:
        SimpleClass(int n1 = 0, int n2 = 0)
        {
            _num1 = n1;
            _num2 = n2;
        }

        void ShowData() const{
            cout << _num1 << ' ' << _num2 << endl;
        }
};

int main()
{
    SimpleClass sc1();  //함수의 원형 선언!

    SimpleClass mysc=sc1();

    mysc.ShowData();
    return 0;
}

SimpleClass sc1()
{
    SimpleClass sc(20,30);
}