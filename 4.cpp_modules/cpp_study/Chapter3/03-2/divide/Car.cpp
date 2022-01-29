#include "Car.h"

void Car::InitMember(char* ID, int fuel)
{
    strcpy(gamerID, ID);
    fuelgauge = fuel;
    curSpeed = 0;
}

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
}

void Car::Break()
{
    if (curSpeed < CAR_CONST::BRK_STEP)
    {
        curSpeed = 0;
        return ;
    }
    curSpeed -= CAR_CONST::BRK_STEP;
}