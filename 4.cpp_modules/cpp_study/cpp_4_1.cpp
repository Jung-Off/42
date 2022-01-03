// #include <iostream>

// class Animal {
//     private:
//     int food;
//     int weight;

//     public:
//     void set_animal(int _food, int _weight) {
//         food = _food;
//         weight = _weight;
//     }
//     void increase_food(int inc) {
//         food += inc;
//         weight += (inc / 3);
//     }
//     void view_stat() {
//         std::cout << "이동물의 food     : " << food << std::endl;
//         std::cout << "이동물의 weight   : " << weight << std::endl;    
//     }
// };

// int main() {
//     Animal animal;
//     animal.set_animal(100, 50);
//     animal.increase_food(30);

//     animal.view_stat();
//     return 0;
// }

# include <iostream>

class Date {
    int _year;
    int _month; // 1 ~ 12
    int _day;   // 1 ~ 31

    public:
    void SetDate(int year, int month, int day)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    void AddDay(int inc)
    {
        _day += inc;
        if (_month == 2){
            if (_day >= 29){
                    _day = _day % 29;
                _day = 1;
                _month += 1;
            }
        }
        else if (_month == 1 || _month == 3 || _month == 5
        || _month == 7 || _month == 8 || _month == 10
        || _month == 12){
            if (_day >= 32){
                _day = _day % 32;
                _day = 1;
                _month += 1;
            }
        }
        else{
            if (_day >= 31){
                    _day = _day % 31;
                _day = 1;
                _month += 1;
            }
        }
        if (_month >= 13)
        {   
            _month = _month % 12;
            _year += 1;
        }
    } ;

    void AddMonth(int inc)
    {
        _month += inc;
        if (_month >= 13)
        {   
            _month = _month % 12;
            _year += 1;
        }
    }

    void AddYear(int inc)
    {
        _year += inc;
    }

    void ShowDate()
    {
        std::cout << "-- " << _year << "년" << _month << "월" << _day << "일" << " --" << std::endl;
    }
};


int main()
{
    Date Calander;
    Calander.SetDate(2021, 1, 1);
    Calander.ShowDate();
    
    for(int i = 0; i < 10; i++)
    {
        Calander.AddDay(32);
        Calander.ShowDate();
    }
    std::cout << "AddMonth" << std::endl;
    for(int i = 0; i < 20; i++)
    {
        Calander.AddMonth(1);
        Calander.ShowDate();
    }
    
}

