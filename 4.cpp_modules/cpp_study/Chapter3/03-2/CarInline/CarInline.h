
#ifndef CARINLINE_H
# define CARINLINE_H

#include <iostream>     //
#include <cstring>     //
using namespace std;    //

namespace CAR_CONST
{
    enum
    {
        ID_LEN  = 20,
        MAX_SPD = 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10
    };
}

class Car
{
    private:
    char gamerID[CAR_CONST::ID_LEN]; //소유자 아이디
    int fuelgauge;          //연료량
    int curSpeed;           //현재속도

    public:
    void InitMember(char* ID, int fuel);
    void ShowCarState();    //상태정보 출력
    void Accel();           //엑셀, 속도 증가
    void Break();           // 브레이크, 속도 감소
};

inline void Car::ShowCarState()
{
    cout << "소유자 ID : " << gamerID << endl;
    cout << "연료량 : " << fuelgauge << endl;
    cout << "현재속도 : " << curSpeed << endl << endl;
}

inline void Car::Break()
{
    if (curSpeed < CAR_CONST::BRK_STEP)
    {
        curSpeed = 0;
        return ;
    }
    curSpeed -= CAR_CONST::BRK_STEP;
}

#endif