
#include <iostream>
using namespace std;

class SinivelCap    //콧물 처치용 캡슐
{
    public:
        void Take() const {cout << "콧물이 싹~ 납니다." << endl;}
};

class SneezeCap    //재채기 처치용 캡슐
{
    public:
        void Take() const {cout << "재채기가 멎습니다." << endl;}
};
class SnuffleCap    //코막힘 처치용 캡슐
{
    public:
        void Take() const {cout << "코가 뻥 뚫립니다." << endl;}
};

class CONTAC600
{
    private:
        SinivelCap  _sin;
        SneezeCap   _sne;
        SnuffleCap  _snu;
    public:
    void Take() const
    {
        _sin.Take();
        _sne.Take();
        _snu.Take();
    }
};

class ColdPatient
{
    public:
        void TakeCONTAC600(const CONTAC600 &cap) const {cap.Take();}
};

int main()
{
    CONTAC600 cap;
    ColdPatient sufferer;
    sufferer.TakeCONTAC600(cap);
    return 0;
}