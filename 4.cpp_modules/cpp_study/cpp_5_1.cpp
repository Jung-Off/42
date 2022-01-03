// #include <string.h>
// #include <iostream>

// class MyString {
//     char *string_content; // 문자열 데이터를 가리키는 포인터
//     int string_length;  //문자열 길이
    
//     int memory_capacity; //현재 할당된 용량

//     public:
//     //문자 하나로 생성
//     MyString(char c);
//     //문자열로 부터 생성
//     MyString(const char* str);
//     //복사 생성자
//     MyString(const MyString& str);
//     ~MyString();

//     int length() const;
//     int capacity() const;
//     void reserve(int size);

//     void print() const;
//     void println() const;

//     char at(int i) const;
//     int compare(MyString& str);
//     bool operator==(MyString& str);
// };

// MyString::MyString(char c) {
//     string_content = new char[1];
//     string_content[0] = c;
//     memory_capacity = 1;
//     string_length = 1;
// }
// MyString::MyString(const char* str) {
//     string_length = strlen(str);
//     memory_capacity = string_length;
//     string_content = new char[string_length];

//     for (int i = 0; i != string_length; i++)
//         string_content[i] = str[i];
// }
// MyString::MyString(const MyString& str) {
//     string_length = str.string_length;
//     string_content = new char[string_length];

//     for (int i = 0; i != string_length; i++)
//         string_content[i] = str.string_content[i];
// }
// MyString::~MyString() { delete[] string_content; }
// int MyString::length() const { return string_length; }
// void MyString::print() const {
//     for (int i = 0; i != string_length; i++) std::cout << string_content[i];
// }
// void MyString::println() const {
//     for (int i = 0; i != string_length; i++) std::cout << string_content[i];

//     std::cout << std::endl;
// }
// int MyString::capacity() const { return memory_capacity; }
// void MyString::reserve(int size) {
//     if (size > memory_capacity) {
//         char* prev_string_content = string_content;

//         string_content = new char[size];
//         memory_capacity = size;

//         for (int i = 0; i != string_length; i++)
//             string_content[i] = prev_string_content[i];

//         delete[] prev_string_content;
//     }
//     // 만일 예약하려는 size가 현재 capacity보다 작다면
//     // 아무것도 안해도 된다.
// }
// char MyString::at(int i) const {
//     if (i >= string_length || i < 0)
//         return 0;
//     else
//         return string_content[i];
// }
// int MyString::compare(MyString& str) {
//     // (*this) - (str)을 수행해서 그 1, 0, -1로 그 결과를 리턴한다
//     // 1은 (*this) 가 사전식으로 더 뒤에 온다는 의미. 0은 두 문자열
//     //아 같다는 의미, -1은 (*this) 기 사전식으로 더 앞에 온다는 의미이다.

//     for (int i = 0; i < std::min(string_length, str.string_length); i++) {
//         if (string_content[i] > str.string_content[i])
//             return 1;
//         else if (string_content[i] < str.string_content[i])
//             return -1;
//     }
//     // 여기 까지 했는데 끝나지 않았다면 앞부분 까지 모두 똑같은 것이 된다.
//     // 만일 문자열 길이가 같아면 두 문자열은 아예 같은 문자열이 된다.

//     if (string_length == str.string_length) return 0;

//     // 참고로 abc와 abcd의 크기 비교는 abcd가 더 뒤에 오게 된다.
//     else if(string_length > str.string_length)
//         return 1;
//     return -1;
// }

// bool MyString::operator==(MyString& str) {
//     return !compare(str); // str과 같으면 compare에서 0을 리턴한다.
// }
// int main() {
//     MyString str1("a word");
//     MyString str2("sentence");
//     MyString str3("sentence");

//     if (str1 == str2)
//         std::cout << "str1와 str2 같다." << std::endl;
//     else
//         std::cout << "st1 와 str2는 다르다." << std::endl;
    
//     if (str2 == str3)
//         std::cout << "str2와 str3는 같다." << std::endl;
//     else
//         std::cout << "st2 와 str2는 다르다. " << std::endl;
// }

//Complex 클래스 만들기

#include <iostream>

class Complex {
    private:
        double real, img;
    public:
        Complex(double real, double img) : real(real), img(img) {}
        Complex(const Complex& c) { real = c.real, img = c.img; }

        Complex operator+(const Complex& c) const;
        Complex operator-(const Complex& c) const;
        Complex operator*(const Complex& c) const;
        Complex operator/(const Complex& c) const;

        void println() { std::cout << "( " << real << " , " << img << " ) " << std::endl; }
};

Complex Complex::operator+(const Complex& c) const {
    Complex temp(real + c.real, img + c.img);
    return temp;
}

Complex Complex::operator-(const Complex& c) const {
    Complex temp(real - c.real, img - c.img);
    return temp;
}

Complex Complex::operator*(const Complex& c) const {
    Complex temp(real * c.real -img * c.img, real * c.img + img * c.real);
    return temp;
}

Complex Complex::operator/(const Complex& c) const {
    Complex temp((real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
    (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
    return temp;
}

int main() {
    Complex a(1.0, 2.0);
    Complex b(3.0, -2.0);

    Complex c = a * b;
    c.println();
}