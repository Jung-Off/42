#include <iostream>

using namespace std;

int main()
{
    int num = 12;
    int *ptr = &num;
    int **dptr = &ptr;

    int &ref = num;
    int *(&pref) = ptr;
    int **(&dpref) = dptr;

    cout << ref << endl;
    cout << *pref << endl;
    cout << **dpref << endl;
}
