#include <iostream>
using namespace std;

class SimpleClass
{
    private:
        int _num1;
        int _num2;
    public:
        SimpleClass()
        {
            _num1 = 0;
            _num2 = 0;
        }
        SimpleClass(int n)
        {
            _num1=n;
            _num2=0;
        }
        SimpleClass(int n1, int n2)
        {
            _num1 = n1;
            _num2 = n2;
        }

        // SimpleClass(int n1 = 0, int n2 = 0)
        // {
        //     num1 = n1;
        //     num2 = n2;
        // }

        void ShowData() const{
            cout << _num1 << ' ' << _num2 << endl;
        }
};

int main()
{
    SimpleClass sc1;
    sc1.ShowData();

    SimpleClass sc2(100);
    sc2.ShowData();

    SimpleClass sc3(100, 200);
    sc3.ShowData();
    return 0;
}