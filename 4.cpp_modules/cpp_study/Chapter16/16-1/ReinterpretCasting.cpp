// #include <iostream>
// using namespace std;

// int main()
// {
//     int num = 0x010203;
//     char *ptr = reinterpret_cast<char*>(&num);
    
//     for (int i = 0; i < sizeof(num); i++)
//         cout << static_cast<int>(*(ptr + i)) << endl;

//     return 0;
// }


// #include <iostream>
// using namespace std;
 
// int main()
// {
//     int* p = new int(65);
//     char* ch = reinterpret_cast<char*>(p);
//     cout << *p << endl;
//     cout << *ch << endl;
//     cout << p << endl;

//     printf("%p\n", ch);
//     cout << ch << endl;
//     return 0;
// }

#include <iostream>
using namespace std;

int main()
{
    int num = 72;
    int *ptr = &num;

    int adr = reinterpret_cast<int>(ptr);  //주소 값을 정수로 변환
    cout << "Addr: " << adr << endl;  //주소 값 출력

    int *rptr = reinterpret_cast<int*>(adr);    //정수를 다시 주소 값으로 변환
    cout << "value: " << *rptr << endl;
}