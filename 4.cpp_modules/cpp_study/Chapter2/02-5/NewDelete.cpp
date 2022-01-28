#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

char * MakeStrAdr(int len)
{
    char *str = new char[len];
    return str;
}

int main()
{
    char *str = MakeStrAdr(20);
    strcpy(str, "I am so Happy~");
    cout << str << endl;
    delete []str;
    return 0;
}