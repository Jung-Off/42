// #include <iostream>

// void print(int x) { std::cout << "int : " << x << std::endl; }
// void print(char x) { std::cout << "char : " << x << std::endl; }
// void print(double x) { std::cout << "double : " << x << std::endl; }

// int main() {
//     int a = 1;
//     char b = 'c';
//     double c = 3.2f;

//     print(a);
//     print(b);
//     print(c);

//     return 0;
// }

// #include <iostream>

// void print(int x) { std::cout << "int : " << x << std::endl; }
// void print(double x) { std::cout << "double : " << x << std::endl; }

// int main() {
//     int a = 1;
//     char b = 'c';
//     double c = 3.2f;

//     print(a);
//     print(b);
//     print(c);

//     return 0;
// }

//ambiguous

// #include <iostream>

// void print(int x) { std::cout << "int : " << x << std::endl; }
// void print(char x) { std::cout << "double : " << x << std::endl; }

// int main() {
//     int a = 1;
//     char b = 'c';
//     double c = 3.2f;

//     print(a);
//     print(b);
//     print(c);

//     return 0;
// }

// //Date

// #include <iostream>

// class Date {
//     private:
//         int _year;
//         int _month;
//         int _day;
//     public:
//         void SetDate(int year, int month, int date);
//         void AddDay(int inc);
//         void AddMonth(int inc);
//         void AddYear(int inc);
//         // 해당 월의 총 일 수를 구한다.
//         int GetCurrentMonthTotalDays(int year, int month);

//         void ShowDate();
// };

// void Date::SetDate(int year, int month, int day) {
//     _year = year;
//     _month = month;
//     _day = day;
// }

// int Date::GetCurrentMonthTotalDays(int year, int month) {
//     static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     if (month != 2) {
//         return month_day[month - 1];
//     }
//     else if (year % 4 == 0 && year % 100 != 0) {
//         return 29; //윤년
//     }
//     else {
//         return 28;
//     }
// }

// void Date::AddDay(int inc) {
//     while (true) {
//         // 현재 달의 총 일 수
//         int current_month_total_days = GetCurrentMonthTotalDays(_year, _month);

//         // 같은 달 안에 들어온다면;
//         if (_day + inc <= current_month_total_days) {
//             _day += inc;
//             return ;
//         }
//         else {
//             // 다음달로 넘어가야 한다.
//             inc -= (current_month_total_days - _day + 1);
//             _day = 1;
//             AddMonth(1);
//         }
//     }
// }

// void Date::AddMonth(int inc) {
//     AddYear((inc + _month - 1) / 12);
//     _month = _month + inc % 12;
//     _month = (_month == 12 ? 12 : _month % 12);
// }

// void Date::AddYear(int inc) {
//     _year += inc;
// }

// void Date::ShowDate() {
//     std::cout << "오늘은 " << _year << " 년 " << _month << " 월 " << _day
//                 << " 일 입니다 " << std::endl;
// }

// int main() {
//     Date day;
//     // day.SetDate(2011, 3, 1);
//     day.ShowDate();

//     day.AddDay(30);
//     day.ShowDate();

//     day.AddDay(2000);
//     day.ShowDate();

//     day.SetDate(2012, 1, 31); //윤년
//     day.AddDay(29);
//     day.ShowDate();
    
//     day.SetDate(2012, 8, 4);
//     day.AddDay(2500);
//     day.ShowDate();
//     return 0;
// }

//생성자

// #include <iostream>

// class Date {
//     private:
//         int _year;
//         int _month;
//         int _day;
//     public:
//         void SetDate(int year, int month, int date);
//         void AddDay(int inc);
//         void AddMonth(int inc);
//         void AddYear(int inc);
//         // 해당 월의 총 일 수를 구한다.
//         int GetCurrentMonthTotalDays(int year, int month);

//         void ShowDate();
//     Date(int year, int month, int day)
//     {
//         _year = year;
//         _month = month;
//         _day = day;
//     }
// };

// void Date::SetDate(int year, int month, int day) {
//     _year = year;
//     _month = month;
//     _day = day;
// }

// int Date::GetCurrentMonthTotalDays(int year, int month) {
//     static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     if (month != 2) {
//         return month_day[month - 1];
//     }
//     else if (year % 4 == 0 && year % 100 != 0) {
//         return 29; //윤년
//     }
//     else {
//         return 28;
//     }
// }

// void Date::AddDay(int inc) {
//     while (true) {
//         // 현재 달의 총 일 수
//         int current_month_total_days = GetCurrentMonthTotalDays(_year, _month);

//         // 같은 달 안에 들어온다면;
//         if (_day + inc <= current_month_total_days) {
//             _day += inc;
//             return ;
//         }
//         else {
//             // 다음달로 넘어가야 한다.
//             inc -= (current_month_total_days - _day + 1);
//             _day = 1;
//             AddMonth(1);
//         }
//     }
// }

// void Date::AddMonth(int inc) {
//     AddYear((inc + _month - 1) / 12);
//     _month = _month + inc % 12;
//     _month = (_month == 12 ? 12 : _month % 12);
// }

// void Date::AddYear(int inc) {
//     _year += inc;
// }

// void Date::ShowDate() {
//     std::cout << "오늘은 " << _year << " 년 " << _month << " 월 " << _day
//                 << " 일 입니다 " << std::endl;
// }

// int main() {
//     Date day(2011, 3, 1);
//     // day.SetDate(2011, 3, 1);
//     day.ShowDate();

//     day.AddYear(10);
//     day.ShowDate();

//     return 0;
// }


// #include <iostream>

// class Date {
//     private:
//         int _year;
//         int _month;
//         int _day;
//     public:
//         void SetDate(int year, int month, int date);
//         void AddDay(int inc);
//         void AddMonth(int inc);
//         void AddYear(int inc);
//         // 해당 월의 총 일 수를 구한다.
//         int GetCurrentMonthTotalDays(int year, int month);

//         void ShowDate();
//     Date()
//     {
//         _year = 2012;
//         _month = 7;
//         _day = 12;
//     }
// };

// void Date::SetDate(int year, int month, int day) {
//     _year = year;
//     _month = month;
//     _day = day;
// }

// int Date::GetCurrentMonthTotalDays(int year, int month) {
//     static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     if (month != 2) {
//         return month_day[month - 1];
//     }
//     else if (year % 4 == 0 && year % 100 != 0) {
//         return 29; //윤년
//     }
//     else {
//         return 28;
//     }
// }

// void Date::AddDay(int inc) {
//     while (true) {
//         // 현재 달의 총 일 수
//         int current_month_total_days = GetCurrentMonthTotalDays(_year, _month);

//         // 같은 달 안에 들어온다면;
//         if (_day + inc <= current_month_total_days) {
//             _day += inc;
//             return ;
//         }
//         else {
//             // 다음달로 넘어가야 한다.
//             inc -= (current_month_total_days - _day + 1);
//             _day = 1;
//             AddMonth(1);
//         }
//     }
// }

// void Date::AddMonth(int inc) {
//     AddYear((inc + _month - 1) / 12);
//     _month = _month + inc % 12;
//     _month = (_month == 12 ? 12 : _month % 12);
// }

// void Date::AddYear(int inc) {
//     _year += inc;
// }

// void Date::ShowDate() {
//     std::cout << "오늘은 " << _year << " 년 " << _month << " 월 " << _day
//                 << " 일 입니다 " << std::endl;
// }

// int main() {
//     Date day = Date();
//     Date day2;

//     day.ShowDate();
//     day2.ShowDate();

//     return 0;
// }

//생성자 오버로딩

// #include <iostream>

// class Date {
//     int _year;
//     int _month;
//     int _day;

//     public:
//         void ShowDate();

//     Date() {
//         std::cout << "기본 생성자 호출!" << std::endl;
//         _year = 2012;
//         _month = 7;
//         _day = 12;
//     }

//     Date(int year, int month, int day) {
//         std::cout << "인자 3개인 생성자 호출!" << std::endl;
//         _year = year;
//         _month = month;
//         _day = day;
//     }
// };

// void Date::ShowDate() {
//     std::cout << "오늘은 " << _year << " 년 " << _month << " 월 " << _day
//         << " 일 입니다 " << std::endl;
// }

// int main() {
//     Date day = Date();
//     Date day2(2012, 10, 31);

//     day.ShowDate();
//     day2.ShowDate();

//     return 0;
// }

//생각해보기

#include <iostream>

class Point {
    int _x, _y;

    public:
        Point(int pos_x, int pos_y){
            _x = pos_x;
            _y = pos_y;
        }
        int GetX() const { return _x; };
        int GetY() const { return _y; };
};

class Geometry {
    public:
        Geometry() {
            num_points = 0;
        }
        void AddPoint(const Point &point) {
            point_array[num_points ++] = new Point(point.GetX(), point.GetY());
        }

    //모든 점들 간의 거리를 출력하는 함수
    void PrintDistanve()
    {
        for (int i = 0; i < num_points; ++i)
        {
            std::cout << "점 x 는:" << point_array[i]->GetX() << std::endl;
            std::cout << "점 y 는:" << point_array[i]->GetY() << std::endl;
        }
    }

    //모든 점들을 잇는 직선들 간의 교점의 수를 출력
    void PrintNumMeets();

    private:
    //점 100개를 보관하는 배열
    Point* point_array[100];
    int num_points;
};

int main()
{
    Geometry Geo;
    Point point_a(1, 2);
    Point point_b(3, 4);

    Geo.AddPoint(point_a);
    Geo.AddPoint(point_b);
    Geo.PrintDistanve();



}