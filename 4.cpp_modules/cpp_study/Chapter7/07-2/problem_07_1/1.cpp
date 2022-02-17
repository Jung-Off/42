#include <iostream>
using namespace std;

class Car // 기본 연료 자동차
{
    private:
        int gasolineGauge;
    public:
        int GetGasGauge()
        {
            return gasolineGauge;
        }
        Car(int Gauge) : gasolineGauge(Gauge)
        {
            cout << "Car(int Gauge)" << endl;
        }
};

class HybridCar : public Car    // 하이브리드 자동차
{
    private:
        int electricGauge;
    public:
        int GetElecGauge()
        {
            return electricGauge;
        }
        HybridCar(int elec, int gasoline) : electricGauge(elec), Car(gasoline)
        {
            cout << "HybridCar(int elec, int gasoline)" << endl;
        }
};

class HybridWaterCar : public HybridCar // 하이브리드 워터카
{
    private:
        int waterGauge;
    public:
        void ShowCurrentGauge()
        {
            cout << "잔여 가솔린: " << GetGasGauge() << endl;
            cout << "잔여 전기량: " << GetElecGauge() << endl;
            cout << "잔여 워터량: " << waterGauge << endl;
        }
        HybridWaterCar(int water, int elec, int gasoline)
            :   waterGauge(water), HybridCar(elec, gasoline)   
        {
            cout << "HybridWaterCar(int water, int elec, int gasoline)" << endl;
        }
};

int main()
{
    cout << "==== car" << endl;
    Car car(10);
    cout << car.GetGasGauge() << endl;
    cout << "==== car" << endl << endl;

    cout << "==== Hcar" << endl;
    HybridCar Hcar(10, 20);
    cout << Hcar.GetElecGauge() << endl;
    cout << Hcar.GetGasGauge() << endl;
    cout << "==== Hcar" << endl << endl;

    cout << "==== HWcar" << endl;
    HybridWaterCar HWcar(10, 20 ,30);
    cout << "==== HWcar" << endl << endl;
    HWcar.ShowCurrentGauge();
}