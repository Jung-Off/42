
#include <iostream>

class Calculator
{
    private:
        int _add;
        int _div;
        int _min;
        int _mul;
    public:
        void Init(void);
        float Add(float a, float b);
        float Div(float a, float b);
        float Mul(float a, float b);
        float Min(float a, float b);
        void ShowOpCount();
};

void Calculator::Init(void)
{
    _add = 0;
    _div = 0;
    _min = 0;
    _mul = 0;
}

float Calculator::Add(float a, float b)
{
    float sum;
    sum = a + b;
    _add++;
    return (sum);
}

float Calculator::Div(float a, float b)
{
    if (b == 0)
    {
        std::cout << " do not this program ";
        return 0;
    }
     
    float div;
    div = a / b;
    _div++;
    return (div);
}

float Calculator::Mul(float a, float b)
{
    float mul;
    mul = a * b;
    _mul++;
    return (mul);
}

float Calculator::Min(float a, float b)
{
    float min;
    min = a - b;
    _min++;
    return (min);
}

void Calculator::ShowOpCount(void)
{
    std::cout << "덧셈 : " << _add << " " <<
     "뺄셈 : " << _min << " " <<
     "곱셈 : " << _mul << " " <<
     "나눗셈 : " << _div << " " << std::endl;
}

int main()
{
    Calculator cal;
    cal.Init();
    std::cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << std::endl;
    std::cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << std::endl;
    std::cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << std::endl;
    std::cout << "2.2 * 2.0 = " << cal.Mul(2.2, 2.0) << std::endl;
    std::cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << std::endl;
    std::cout << "4.9 / 0 = " << cal.Div(4.9, 0) << std::endl;
    cal.ShowOpCount();
}