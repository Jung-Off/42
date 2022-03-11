#include <iostream>

using namespace std;

template <typename T>
T add (T a, T b)
{
    return (a + b);
}

int main()
{
    cout << add<int>(15, 20) << endl;
    cout << add<double>(2.9, 3.7) << endl;
    cout << add<int>(3.2, 3.2) << endl;
    cout << add<double>(3.14, 2.75) << endl;
}