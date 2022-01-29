#include "CarInline.h"

void Car::InitMember(char* ID, int fuel)
{
    strcpy(gamerID, ID);
    fuelgauge = fuel;
    curSpeed = 0;
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
