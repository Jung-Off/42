#include <iostream>
using namespace std;

void Divide(int num1, int num2)
{
    if (num2 == 0)
        throw num2;
        cout << "나눈셈의 몫: " << num1/num2 << endl;
        cout << "나눈셈의 나머지: " << num1%num2 << endl;
}


int main()
{
    int num1, num2;
    cout << "두개의 숫자 입력 : ";
    cin >> num1 >> num2;
    try
    {
        Divide(num1, num2);
    }
    catch(const int num2)
    {
        cout << "제수는 " << num2 << "이 될 수 없습니다." << endl;
        cout << "프로그램을 다시 실행하세요." << endl;
    }
    cout << "end of main" << endl;
    return 0;
}