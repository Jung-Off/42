#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
    private:
        int bullet; //장전된 총알의 수
    public:
        Gun(int bnum) : bullet(bnum)
        {}
        void Shot()
        {
            cout << "BBANG!" << endl;
            bullet--;
        }
};

class Police : public Gun
{
    private:
        int handcuffs;
    public:
        Police(int bnum, int buff)
            : Gun(bnum), handcuffs(buff)
        {}
        void PutHandcuff()
        {
            cout << "SNAP" << endl;
            handcuffs--;
        }
};

int main()
{
    Police pman(5, 3);
    pman.Shot();
    pman.PutHandcuff();
    return 0;
}