#include <iostream>
namespace mystd
{
    using namespace std;

    class ostream
    {
        public:
            ostream& operator<< (char * str)
            {
                printf("%s", str);
                return(*this);
            }
            ostream& operator<< (char  str)
            {
                printf("%c", str);
                return(*this);
            }
            ostream& operator<< (int num)
            {
                printf("%d", num);
                return(*this);
            }
            ostream& operator<< (double e)
            {
                printf("%g", e);
                return(*this);
            }
            ostream& operator<< (ostream& (*fp)(ostream &ostm))
            {
                fp(*this);
                return(*this);
            }
    };

    ostream& endl(ostream & ostm)
    {
        ostm << '\n';
        fflush(stdout);
        return ostm;
    }

    ostream cout;
}

int main()
{
    using mystd::cout;
    using mystd::endl;

    cout << 3.14 << endl << 123 << endl;

    // cout << "Simple String";
    // cout << endl;
    // cout << 3.14;
    // cout << endl;
    // cout << 123;
    // endl(cout);
    return 0;
}