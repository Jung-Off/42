#include <iostream>
using namespace std;

// class Car
// {
//     private:
//         int fuelGauge;
//     public:
//         Car(int fuel) :fuelGauge(fuel)
//         {}
//         void ShowCarState() { cout << "잔여 연료량: " << fuelGauge << endl; }
// };

// class Truck : public Car
// {
//     private:
//         int freightWeight;
//     public:
//         Truck(int fuel, int weight)
//             : Car(fuel), freightWeight(weight)
//         {}
//         void ShowTruckState()
//         {
//             ShowCarState();
//             cout << "화물의 무게: " << freightWeight << endl;
//         }
// };

// int main()
// {
//     Car* pcar1 = new Truck(80, 200);
//     Truck *pTruck1 = static_cast<Truck*>(pcar1); //컴파일
//     pTruck1->ShowTruckState();

//     Car* pcar2 = new Car(120);
//     Truck *pTruck2 = static_cast<Truck*>(pcar2); //컴파일 에러
//     pTruck2->ShowTruckState();

//     return 0;
// }

int main()
{
    const int num = 20;
    int * ptr = (int*)&num; //const 상수의 포인터는 const 포인터 이다!
    *ptr = 30;              //const 상수 num의 갓ㅂ이 실제로 변경된다.
    cout << *ptr << endl;   //30이 출력된다.

    float * adr = (float*)ptr; //int형 포인터를 float형으로 변환한다
    cout << *adr << endl;   //저장된 데이터를 float형으로 해석해서 출력한다.
}