#include <iostream>
using namespace std;

void ShowString(char * str)
{
    cout << str << endl;
}

void ShowAddResult(int& n1, int& n2)
{
    cout << n1 + n2 << endl;
}

int main()
{
    const char *name = "Lee Sung Ju";
    //여기서 선언된 포인터 변수 name 은 const char *형
    //ShowString의 매개변수는 char*형이다.
    //name은 ShowString에 함수의 인자로 전달 될 수 없다.
    //name이 char*이고 매개변ㄴ수가 const char*이라면 인자로 전달 가능

    ShowString(const_cast<char*>(name));
    //인자로 전달하기 위해 name의 const를 제거하는 형태로 형 변환을 진행
    
    const int& num1 =100;
    const int& num2 =200;
    //const int&를 int&로
    ShowAddResult(const_cast<int&>(num1), const_cast<int&>(num2));
    return 0;
}

