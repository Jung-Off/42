#include <iostream>
using namespace std;

class Car
{
    private:
        int fuelGauge;
    public:
        Car(int fuel) :fuelGauge(fuel)
        {}
        void ShowCarState() { cout << "잔여 연료량: " << fuelGauge << endl; }
};

class Truck : public Car
{
    private:
        int freightWeight;
    public:
        Truck(int fuel, int weight)
            : Car(fuel), freightWeight(weight)
        {}
        void ShowTruckState()
        {
            ShowCarState();
            cout << "화물의 무게: " << freightWeight << endl;
        }
};

int main()
{
    Car* pcar1 = new Truck(80, 200);
    Truck *pTruck = dynamic_cast<Truck*>(pcar1); //컴파일 에러

    Car* pcar2 = new Car(120);
    Truck *pTruck = dynamic_cast<Truck*>(pcar2); //컴파일 에러

    Truck* pTruck3 = new Truck(70, 150);
    Car* pcar3 = dynamic_cast<Car*>(pTruck3); //컴파일 ok
    return 0;
}