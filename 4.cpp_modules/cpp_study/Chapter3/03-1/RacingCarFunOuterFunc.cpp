#include <iostream>
using namespace std;

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

struct Car
{
    char gamerID[CAR_CONST::ID_LEN]; //소유자 아이디
    int fuelgauge;          //연료량
    int curSpeed;           //현재속도

    void ShowCarState();    //상태정보 출력
    void Accel();           //엑셀, 속도 증가
    void Break();           // 브레이크, 속도 감소
};

void Car::ShowCarState()
{
    cout << "소유자 ID : " << gamerID << endl;
    cout << "연료량 : " << fuelgauge << endl;
    cout << "현재속도 : " << curSpeed << endl << endl;
}

void Car::Accel()
{
    if (fuelgauge <= 0)
        return ;
    else
        fuelgauge -= CAR_CONST::FUEL_STEP;
    if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
    {
        curSpeed = CAR_CONST::MAX_SPD;
        return ;
    }
    curSpeed += CAR_CONST::ACC_STEP;
};

void Car::Break()
{
    if (curSpeed < CAR_CONST::BRK_STEP)
    {
        curSpeed = 0;
        return ;
    }
    curSpeed -= CAR_CONST::BRK_STEP;
};


int main()
{
    Car run99 = {"run99", 100, 0};
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();
    return 0;
}