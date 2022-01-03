// #include <iostream>

// int change_val(int *p) {
// 	*p = 3;

// 	return 0;
// }

// int main() {
// 	int number = 5;

// 	std::cout << number << std::endl;
// 	change_val(&number);
// 	std::cout << number << std::endl;
// }

// #include <iostream>

// int main() {
// 	int a = 3;
// 	int& another_a = a;

// 	another_a = 5;
// 	std::cout << "a : " << a << std::endl;
// 	std::cout << "another_a : " << another_a << std::endl;

// 	return 0;
// }


// #include <iostream>

// int change_val(int &p) {
// 	p = 3;

// 	return 0;
// }

// int main() {
// 	int number = 5;

// 	std::cout << number << std::endl;
// 	change_val(number);
// 	std::cout << number << std::endl;
// }

// #include <iostream>

// int main() {
// 	int x;
// 	int& y = x;
// 	int& z = y;

// 	x = 1;
// 	std::cout << "x: " << x << "y: " << y << "z: " << z << std::endl;
// 	//1 1 1
// 	y = 2;
// 	std::cout << "x: " << x << "y: " << y << "z: " << z << std::endl;
// 	//2 2 1
// 	z = 3;
// 	std::cout << "x: " << x << "y: " << y << "z: " << z << std::endl;
// 	//2 3 3
// }

// #include <iostream>

// int main() {
// 	int arr[3] = {1, 2, 3};
// 	int(&ref)[3] = arr;

// 	std::cout << arr[0] << arr[1] << arr[2] << std::endl;
// 	ref[0] = 2;
// 	ref[1] = 3;
// 	ref[2] = 1;

// 	std::cout << arr[0] << arr[1] << arr[2] << std::endl;
// 	return 0;
// }



//여기 잘 이해하기
// 1. 함수에서 값을 리턴  							 값
// 											참조자
// 											상수 참조자
// 2. 함수에서 참조자 리턴(함수의 참조자 리턴은 주의)	   값으로 받기
// 											참조자로 받기
// 											상수 참조자로 받기

// int function_returnvtov()
// {
// 	int a = 1;

// 	return a;
// }

// int function_returnvtoref()
// {
// 	int a = 2;

// 	return a;
// }

// int function_returnvtoconstref()
// {
// 	int a = 3;

// 	return a;
// }

// int& function_returnreftov(int& a)
// {
// 	//int &a = d_copy; // d_copy의 다른 이름 a
// 	a = 4;
// 	// a가 (d_copy가) 4
// 	return a;
// 	// int& ret = a // a의 다른 이름 ret 
// }

// int& function_returnreftoref(int &a)
// {
// 	a = 5;

// 	return a;
// }

// int& function_returnreftoconstref(int &a)
// {
// 	a = 6;

// 	return a;
// }

// #include <iostream>

// int main()
// {
// 	int a = 0;
	
// 	//원래하던거
// 	//value = return value
// 	std::cout << "1. value = return value " << a << std::endl; 
// 	std::cout << "before a : " << a << std::endl; 
// 	a = function_returnvtov();
// 	std::cout << "after a : " << a << std::endl;
// 	std::cout << std::endl;

// 	//ref = return value
// 	int b = 0;
// 	//int& b_copy = function_returnvtoref(); //notcompile
// 	std::cout << "2. ref = return value " << b << std::endl; 
// 	//std::cout << "b : " << b << " b_copy : " << b_copy << std::endl;
// 	std::cout << "b is not compile" << std::endl;
// 	std::cout << std::endl;

// 	//위의 문제를 보완
// 	//const ref = return value
// 	int c = 0;
// 	const int& c_copy = function_returnvtoconstref();
// 	std::cout << "3. const ref = return value " << c << std::endl; 
// 	std::cout << "c_copy : " << c_copy << std::endl; 
// 	//함수의 변수에는 접근 할 수 없지만 살아있다.
// 	std::cout << std::endl;
	
// 	//return ref로 받아오는 것을 main에서 부터 넘겨준 변수로 
// 	//function 의 지역변수 형태로 main으로 return시키면 문제가 생김
	
// 	//value = return ref
// 	int d = 0;
// 	int& d_copy = d;
// 	int d_temp = 0;
// 	std::cout << "4. value = return ref " << d << std::endl; 
// 	std::cout << "before function" << std::endl;
// 	std::cout << "d : " << d << " d_copy : " << d_copy << " d_temp : " << d_temp << std::endl;
// 	d_temp = function_returnreftov(d_copy); //여기서 이미 d_copy, d의 값이 이미바뀜
// 	//ret의 값을 d_temp에 넣어준다. 
// 	std::cout << "after function" << std::endl;
// 	std::cout << "d : " << d << " d_copy : " << d_copy << " d_temp : " << d_temp << std::endl;
	
// 	//d_temp가 d_copy와 연결되어져 있는지 확인
// 	//연결되어있지 않음 d_temp는 값만 들어가짐
// 	d_temp = 10;
// 	std::cout << "after d_temp : 10" << std::endl;
// 	//연결이 되어있는 걸로
// 	std::cout << "d : " << d << " d_copy : " << d_copy << " d_temp : " << d_temp << std::endl;
// 	std::cout << std::endl;

// 	//ref = return ref
// 	int e = 0;
// 	int &e_copy = e;
// 	std::cout << "5. ref = return ref " << e << std::endl; 
// 	std::cout << "before function" << std::endl;
// 	std::cout << "e : " << e << " e_copy : " << e_copy << std::endl;
// 	int &e_temp = function_returnreftoref(e_copy);
// 	//e_copy는 e의 별명
// 	//함수 안의 int& a = e_copy a는 e_copy의 별명
// 	//a는 5 (e_copy도 5)
// 	//int &ret = a ret은 a의 별명
// 	//ret 은 a 는 e_copy는 e
// 	//int &e_temp = ret 해서 연결됨
// 	//e_temp 는 ret 은 a 는 e_copy는 e 이게 모두 연결이 되어버림
	
// 	//ret의 값을 e_temp에 넣어준다.
// 	std::cout << "after function" << std::endl;
// 	std::cout << "e : " << e << " e_copy : " << e_copy << " e_temp : " << e_temp << std::endl;
// 	//e_temp가 e_copy와 연결되어져 있는지 확인
// 	e_temp = 10;
// 	std::cout << "after e_temp : 10" << std::endl;
// 	//연결이 되어있는 걸로
// 	std::cout << "e : " << e << " e_copy : " << e_copy << " e_temp : " << e_temp << std::endl;
// 	std::cout << std::endl;

// 	//const ref = return ref
// 	int f = 0;
// 	int &f_copy = f;
// 	std::cout << "6. const ref = return ref " << f << std::endl; 
// 	std::cout << "before function" << std::endl;
// 	std::cout << "f : " << f << " f_copy : " << f_copy << std::endl;
// 	const int &f_temp = function_returnreftoconstref(f_copy);
// 	std::cout << "after function" << std::endl;
// 	std::cout << "f : " << f << " f_copy : " << f_copy << " f_temp : " << f_temp << std::endl;
// 	//f_temp가 f_copy와 연결되어져 있는지 확인
// 	// f_temp = 10;
// 	// std::cout << "after f_temp : 10" << std::endl;
// 	//연결이 되어있는 걸로
// 	// std::cout << "f : " << f << " f_copy : " << f_copy << " f_temp : " << f_temp << std::endl;
// 	// std::cout << std::endl;
// 	// std::cout << std::endl;
// 	//여기서는 const int라 f_temp를 변경할 수 없다.


// }

#include <iostream>

int fn1(int &a)
{
	a++;

	return (a);
}

int &fn2(int &a)
{
	a++;

	return (a);
}

int main ()
{
	int x = 10;
	int y = 10;

	int c;

	for (int i = 0; i < 5; ++i)
	{
		std::cout << "x:" << fn1(x) << std::endl;
		std::cout << "y:" << fn2(y) << std::endl;
	}
}