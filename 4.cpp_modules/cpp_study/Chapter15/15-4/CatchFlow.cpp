#include <iostream>
using namespace std;

class AAA
{
    public:
        void ShowYou() { cout << "AAA exceeption!" << endl; }
};

class BBB : public AAA
{
    public:
        void ShowYou() { cout << "BBB exceeption!" << endl; }
};

class CCC : public BBB
{
    public:
        void ShowYou() { cout << "CCC exceeption!" << endl; }
};

void ExceptionGenerator(int expn)
{
    if (expn == 1)
        throw AAA();
    else if (expn == 2)
        throw BBB();
    else
        throw CCC();
}

int main()
{
    try
    {
        ExceptionGenerator(3);
        ExceptionGenerator(2);
        ExceptionGenerator(1);
    }
    // catch(AAA& expn)
    // {
    //     cout << "catch(AAA& expn)" <<endl;
    //     expn.ShowYou();
    // }
    // catch(BBB& expn)
    // {
    //     cout << "catch(BBB& expn)" <<endl;
    //     expn.ShowYou();
    // }
    // catch(CCC& expn)
    // {
    //     cout << "catch(CCC& expn)" <<endl;
    //     expn.ShowYou();
    // }
    
    catch(CCC& expn)
    {
        cout << "catch(CCC& expn)" <<endl;
        expn.ShowYou();
    }
    catch(BBB& expn)
    {
        cout << "catch(BBB& expn)" <<endl;
        expn.ShowYou();
    }
    catch(AAA& expn)
    {
        cout << "catch(AAA& expn)" <<endl;
        expn.ShowYou();
    }
}