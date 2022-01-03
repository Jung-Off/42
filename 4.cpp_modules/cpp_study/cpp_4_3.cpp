
// #include <iostream>

// class Marine {
//     int _hp;                 // 마린 체력
//     int _CoordX, _CoordY;   // 마린 위치
//     int _damage;             // 마린 공격력
//     bool _IsDead;
// 	char *_name;				// 마린 이름

//     public:
//     Marine();               // 기본 생성자
// 	Marine(int x, int y, const char * marine_name);	// 이름까지 지정 
//     Marine(int x, int y);   // x, y 좌표에 마린 생성
// 	~Marine();

//     int attack();           // 데미지를 리턴한다
//     void be_attacked(int damage_earn);  // 입는 데미지
//     void move(int x, int y);            // 새로운 위치

//     void show_status();		// 상태를 보여준다.
// };

// Marine::Marine() {
// 	_hp = 50;
// 	_CoordX = _CoordY = 0;
// 	_damage = 5;
// 	_IsDead = false;
// 	_name = NULL;
// }

// Marine::Marine(int x, int y, const char* marine_name) {
// 	_name = new char[strlen(marine_name) + 1];
// 	strcpy(_name, marine_name);

// 	_CoordX = x;
// 	_CoordY = y;
// 	_hp = 50;
// 	_damage = 5;
// 	_IsDead = false;
// }

// Marine::Marine(int x, int y) {
// 	_CoordX = x;
// 	_CoordY = y;
// 	_hp = 50;
// 	_damage = 5;
// 	_IsDead = false;
// 	_name = NULL;
// }

// void Marine::move(int x, int y) {
// 	_CoordX = x;
// 	_CoordY = y;
// }

// int Marine::attack() { return _damage; }

// void Marine::be_attacked(int damage_earn) {
// 	_hp -= damage_earn;
// 	if (_hp <= 0)
// 		_IsDead = true;
// }

// void Marine::show_status() {
// 	std::cout << " *** Marine : " << _name << " *** " << std::endl;
// 	std::cout << " Location : ( " << _CoordX << " , " << _CoordY << " ) "
// 				<< std::endl;
// 	std::cout << " HP : " << _hp << std::endl;
// }

// Marine::~Marine() {
// 	std::cout << _name << " 의 소멸자 호출 ! " << std::endl;
// 	if (_name != NULL) {
// 		delete[] _name;
// 	}
// }
// int main() {
// 	Marine marine1(2, 3);
// 	Marine marine2(3, 5);

// 	marine1.show_status();
// 	marine2.show_status();

// 	std::cout << std::endl << " 마린 1이 마린 2를 공격! " << std::endl;
// 	marine2.be_attacked(marine1.attack());

// 	marine1.show_status();
// 	marine2.show_status();
// }

// 배열을 사용하여 만들기
// int main() {
// 	Marine* marines[100];

// 	marines[0] = new Marine(2, 3, "Marine 2");
// 	marines[1] = new Marine(1, 5, "Marine 1");

// 	marines[0]->show_status();
// 	marines[1]->show_status();

// 	std::cout << std::endl << "마린 1이 마린 2를 공격! " << std::endl;

// 	marines[0]->be_attacked(marines[1]->attack());

// 	marines[0]->show_status();
// 	marines[1]->show_status();

// 	delete marines[0];
// 	delete marines[1];
// }

// 소멸자 호출 확인하기
// #include <string.h>
// #include <iostream>

// class Test {
// 	char _c;

// 	public:
// 	Test(char c) {
// 		_c = c;
// 		std::cout << "생성자 호출 " << _c << std::endl;
// 	}
// 	~Test() { std::cout << "소멸자 호출 " << _c << std::endl; }
// };

// void simple_function() { Test b('b'); }
// int main() {
// 	Test a('a');
// 	simple_function();
// }

// 복사생성자
// 포토캐논
// #include <string.h>
// #include <iostream>

// class Photon_Cannon {
// 	int _hp, _shield;
// 	int _CoordX, _CoordY;
// 	int _damage;

// 	public:
// 	Photon_Cannon(int x, int y);
// 	Photon_Cannon(const Photon_Cannon & pc);

// 	void show_status();
// };

// Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc)
// {
// 	std::cout << "복사 생성자 호출 !" << std::endl;
// 	_hp = pc._hp;
// 	_shield = pc._shield;
// 	_CoordX = pc._CoordX;
// 	_CoordY = pc._CoordY;
// 	_damage = pc._damage;
// }

// Photon_Cannon::Photon_Cannon(int x, int y)
// {
// 	std::cout << "생성자 호출 !" << std::endl;
// 	_hp = _shield = 100;
// 	_CoordX = x;
// 	_CoordY = y;
// 	_damage = 20;
// }

// void Photon_Cannon::show_status()
// {
// 	std::cout << "Photon Cannon " << std::endl;
// 	std::cout << "Location : ( " << _CoordX << " , " << _CoordY << " ) "
// 				<< std::endl;
// 	std::cout << " HP : " << _hp << std::endl;
// }

// int main() {
// 	Photon_Cannon pc1(3, 3);
// 	Photon_Cannon pc2(pc1);
// 	Photon_Cannon pc3 = pc2;

// 	pc1.show_status();
// 	pc2.show_status();
// }

// 디폴트 복사 생성자의 한계

// #include <string.h>
// #include <iostream>

// class Photon_Cannon {
//   int _hp, _shield;
//   int _CoordX, _CoordY;
//   int _damage;

//   char *_name;

//  public:
//   Photon_Cannon(int x, int y);
//   Photon_Cannon(int x, int y, const char *cannon_name);
//   ~Photon_Cannon();

//   void show_status();
// };

// Photon_Cannon::Photon_Cannon(int x, int y) {
//   _hp = _shield = 100;
//   _CoordX = x;
//   _CoordY = y;
//   _damage = 20;

//   _name = NULL;
// }
// Photon_Cannon::Photon_Cannon(int x, int y, const char *cannon_name) {
//   _hp = _shield = 100;
//   _CoordX = x;
//   _CoordY = y;
//   _damage = 20;

//   _name = new char[strlen(cannon_name) + 1];
//   strcpy(_name, cannon_name);
// }
// Photon_Cannon::~Photon_Cannon() {
//   // 0 이 아닌 값은 if 문에서 true 로 처리되므로
//   // 0 인가 아닌가를 비교할 때 그냥 if(name) 하면
//   // if(name != 0) 과 동일한 의미를 가질 수 있다.

//   // 참고로 if 문 다음에 문장이 1 개만 온다면
//   // 중괄호를 생략 가능하다.

//   if (_name) delete[] _name;
// }
// void Photon_Cannon::show_status() {
//   std::cout << "Photon Cannon :: " << _name << std::endl;
//   std::cout << " Location : ( " << _CoordX << " , " << _CoordY << " ) "
//             << std::endl;
//   std::cout << " HP : " << _hp << std::endl;
// }
// int main() {
//   Photon_Cannon pc1(3, 3, "Cannon");
//   Photon_Cannon pc2 = pc1;

//   pc1.show_status();
//   pc2.show_status();
// }

//디폴트 복사 생성자의 한계해결
// #include <string.h>
// #include <iostream>

// class Photon_Cannon {
// 	int _hp, _shield;
// 	int _CoordX, _CoordY;
// 	int _damage;

// 	char *_name;

// 	public:
// 		Photon_Cannon(int x, int y);
// 		Photon_Cannon(int x, int y, const char *cannon_name);
// 		Photon_Cannon(const Photon_Cannon& pc);
// 		~Photon_Cannon();

// 		void show_status();
// };

// Photon_Cannon::Photon_Cannon(int x, int y) {
// 	_hp = _shield = 100;
// 	_CoordX = x;
// 	_CoordY = y;
// 	_damage = 20;

// 	_name = NULL;
// }

// Photon_Cannon::Photon_Cannon(int x, int y, const char *cannon_name) {
//   _hp = _shield = 100;
//   _CoordX = x;
//   _CoordY = y;
//   _damage = 20;

//   _name = new char[strlen(cannon_name) + 1];
//   strcpy(_name, cannon_name);
// }

// Photon_Cannon::Photon_Cannon(const Photon_Cannon &pc) {
//   std::cout << "복사 생성자 호출! " << std::endl;
//   _hp = pc._hp;
//   _shield = pc._shield;
//   _CoordX = pc._CoordX;
//   _CoordY = pc._CoordY;
//   _damage = pc._damage;

//   _name = new char[strlen(pc._name) + 1];
//   strcpy(_name, pc._name);
// }

// Photon_Cannon::~Photon_Cannon() {
// 	// 0이 아닌 값은 if 문에서 true로 처리되므로
// 	// 0인가 아닌가를 비교할 때 그냥 if(name)하면
// 	// if(name != 0)과 동일한 의미

// 	// 참고로 if문 다음에 문장이 1개면
// 	// 중괄호 생략 가능
// 	if (_name) delete[] _name;
// }

// void Photon_Cannon::show_status() {
//   std::cout << "Photon Cannon :: " << _name << std::endl;
//   std::cout << " Location : ( " << _CoordX << " , " << _CoordY << " ) "
//             << std::endl;
//   std::cout << " HP : " << _hp << std::endl;
// }

// int main() {
// 	Photon_Cannon pc1(3, 3, "Cannon");
// 	Photon_Cannon pc2 = pc1;

// 	pc1.show_status();
// 	pc2.show_status();
// }

// 생각해보기
#include <iostream>

class string {
	char *_str;
	int _len;

	public:
		string(char c, int n); // 문자 c가 n개 있는 문자열로 정의
		string(const char *s);
		string(const string &s);
		~string();

		void add_string(const string &s);	// str 뒤에 s를 붙인다.
		void copy_string(const string &s);	// str에 s를 복하나다.
		int strlen();						// 문자열 길이 리턴

		void print_string();
};

string::string(char c, int n)
{
	_len = n;
	int i;
	_str = new char[_len + 1];
	for (i = 0; i < _len; i++)
		_str[i] = c;
	_str[i] = (char)NULL;
}

string::string(const char *s)
{
	_len = 0;
	while(*s)
	{
		_len++;
		s++;
	}
	_str = new char[_len + 1];
	s -= _len;
	int i;
	for (i = 0; i < _len; i++, s++)
		_str[i] = *s;
	_str[i] = (char)NULL;
}

string::string(const string &s)
{
	_len = s._len;
	_str = new char[_len + 1];
	char *c = s._str;
	int i;
	for (i = 0; i < _len; i++, c++)
		_str[i] = *c;
	_str[i] = (char)NULL;
}

string::~string(){
	if(_str)
		delete[] _str;
}

void string::add_string(const string &s) {
	int new_len = _len + s._len;
	char *new_string = new char[new_len + 1];
	char *original = _str;
	char *add = s._str;
	int i = 0;
	while(*original){
		new_string[i++] = *original;
		original++;
	}
	while(*add){
		new_string[i++] = *add;
		add++;
	}
	new_string[i] = (char)NULL;

	if(_str){
		delete[] _str;
	}
	_len = new_len;
	_str = new char[_len + 1];
	char *temp = new_string;
	i = 0;
	while(*temp) {
		_str[i++] = *temp;
		temp++;
	}
	_str[i] = (char)NULL;
}

void string::copy_string(const string &s) {
	if (_str) {
		delete[] _str;
	}
	_len = s._len;
	_str = new char[_len + 1];
	char *c = s._str;
	int i;
	for (i = 0; i < _len; i++, c++) {
		_str[i] = *c;
	}
	_str[i] = (char)NULL;
}

int string::strlen() { return _len ;}

void string::print_string() {
	std::cout << "내용 : " << _str << std::endl;
}

int main()
{
	string s1('o', 4);
	string s2("hello");
	string s3(s1);
	string s4(s2);

	s1.print_string(); //oooo
	std::cout << "1. 길이: " << s1.strlen() << std::endl; //4

	s2.print_string(); //hello
	std::cout << "2. 길이: " << s2.strlen() << std::endl; //5

	s3.print_string(); //oooo
	std::cout << "3. 길이: " << s3.strlen() << std::endl; //4

	s4.print_string(); //hello
	std::cout << "4. 길이: " << s4.strlen() << std::endl; //5

	s1.add_string(s2);
	s1.print_string(); //oooohello
	std::cout << "5. 길이: " << s1.strlen() << std::endl; //9

	s1.add_string(s3);
	s1.print_string(); //oooohellooooo
	std::cout << "6. 길이: " << s1.strlen() << std::endl; //13

	s1.add_string(s3);
	s1.add_string(s4);
	s1.print_string(); //ooooabcdeooooooooabcde
	std::cout << "7. 길이: " << s1.strlen() << std::endl; //22

	s3.copy_string(s1);	//ooooabcdeooooooooabcde
	s1.copy_string(s2);	//hello

	s1.print_string(); //hello
	std::cout << "8. 길이: " << s1.strlen() << std::endl; //5

	s3.print_string(); //ooooabcdeooooooooabcde
	std::cout << "9. 길이: " << s3.strlen() << std::endl; //22
	return 0;
}