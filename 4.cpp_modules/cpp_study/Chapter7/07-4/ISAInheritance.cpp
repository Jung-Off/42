#include <iostream>
#include <cstring>
using namespace std;

class Computer
{
    private:
        char owner[30];
    public:
        Computer(char* name)
        {
            strcpy(owner, name);
        }
        void CalCulate()
        {
            cout << "요청 내용을 계산 합니다." << endl;
        }
};

class NoteBookComp : public Computer
{
    private:
        int Battery;
    public:
        NoteBookComp(char* name, int initChag)
            : Computer(name), Battery(initChag)
        {}
        void Charging() { Battery+=5; }
        void UseBattery() { Battery-=1; }
        void MovingCal()
        {
            if (GetBatteryInfo() < 1)
            {
                cout << "충전이 필요합니다." << endl;
                return ;
            }
            cout << "이동하면서 " ;
            CalCulate();
            UseBattery();
        }
        int GetBatteryInfo() { return Battery; }
};

class TabletNotebook : public NoteBookComp
{
    private:
        char regstPenModel[50];
    public:
        TabletNotebook(char *name, int initChag, char *pen)
            :NoteBookComp(name, initChag)
        {
            strcpy(regstPenModel, pen);
        }
        void Write(char * penInfo)
        {
            if (GetBatteryInfo() < 1)
            {
                cout << "충전이 필요합니다. " << endl;
                return ;
            }
            if (strcmp(regstPenModel, penInfo) != 0)
            {
                cout << "등록된 펜이 아닙니다.";
                return ;
            }
            cout << "필기 내용을 처리합니다." << endl;
            UseBattery();
        }
};

int main()
{
    NoteBookComp nc("이수종", 5);
    TabletNotebook tn("정수영", 5, "ISE-241-242");
    nc.MovingCal();
    tn.Write("ISE-241-242");
    return 0;
}
