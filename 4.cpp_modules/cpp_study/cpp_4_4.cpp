
//생성자의 초기화 리스트(initializer list)
// #include <iostream>

// class Marine {
//     int _hp;                // 마린 체력
//     int _CoordX, _CoordY;   // 마린 위치
//     int _damage;            // 공격력
//     bool _isDead;

//     public:
//     Marine();               // 기본 생성자
//     Marine(int x, int y);   // x, y 좌표에 마린 생성

//     int attack();           // 데미지를 리턴한다.
//     void be_attacked(int damage_earn);  //입는 데미지
//     void move(int x, int y);// 새로운 위치

//     void show_status();     //상태를 보여준다.
// };

// Marine::Marine() : _hp(50), _CoordX(0), _CoordY(0), _damage(5), _isDead(false) {}

// Marine::Marine(int x, int y)
//     : _CoordX(x), _CoordY(y), _hp(50), _damage(5), _isDead(false) {}

// void Marine::move(int x, int y) {
//     _CoordX = x;
//     _CoordY = y;
// }

// int Marine::attack() { return _damage; }
// void Marine::be_attacked(int damage_earn) {
//     _hp -= damage_earn;
//     if (_hp <= 0) _isDead = true;
// }
// void Marine::show_status() {
//     std::cout << " *** Marine *** " << std::endl;
//     std::cout << " Location : ( " << _CoordX << " , " << _CoordY << " ) " 
//         << std::endl;
//     std::cout << " HP : " << _hp << std::endl;    
// }

// int main() {
//     Marine marine1(2, 3);
//     Marine marine2(2, 3);

//     marine1.show_status();
//     marine2.show_status();
// }


// ----------------------------------
//const int default_damage;  // 기본 공격력 추가

// #include <iostream>

// class Marine {
//     int _hp;                // 마린 체력
//     int _CoordX, _CoordY;   // 마린 위치
//     bool _isDead;

//     const int default_damage;   //기본 공격력

//     public:
//     Marine();               // 기본 생성자
//     Marine(int x, int y);   // x, y 좌표에 마린 생성

//     int attack();           // 데미지를 리턴한다.
//     void be_attacked(int damage_earn);  //입는 데미지
//     void move(int x, int y);// 새로운 위치

//     void show_status();     //상태를 보여준다.
// };

// Marine::Marine() : _hp(50), _CoordX(0), _CoordY(0), default_damage(5), _isDead(false) {}

// Marine::Marine(int x, int y)
//     : _CoordX(x), _CoordY(y), _hp(50), default_damage(5), _isDead(false) {}

// void Marine::move(int x, int y) {
//     _CoordX = x;
//     _CoordY = y;
// }

// int Marine::attack() { return default_damage; }
// void Marine::be_attacked(int damage_earn) {
//     _hp -= damage_earn;
//     if (_hp <= 0) _isDead = true;
// }
// void Marine::show_status() {
//     std::cout << " *** Marine *** " << std::endl;
//     std::cout << " Location : ( " << _CoordX << " , " << _CoordY << " ) " 
//         << std::endl;
//     std::cout << " HP : " << _hp << std::endl;    
// }

// int main() {
//     Marine marine1(2, 3);
//     Marine marine2(2, 3);

//     marine1.show_status();
//     marine2.show_status();

//     std::cout << std::endl << "마린 1 이 마린 2를 공격! " << std::endl;
//     marine2.be_attacked(marine1.attack());

//     marine1.show_status();
//     marine2.show_status();
// }

//----------------------------------------
//const int default_damage관련 생성자 추가


// #include <iostream>

// class Marine {
//     int _hp;                // 마린 체력
//     int _CoordX, _CoordY;   // 마린 위치
//     bool _isDead;

//     const int _default_damage;   //기본 공격력

//     public:
//     Marine();               // 기본 생성자
//     Marine(int x, int y);   // x, y 좌표에 마린 생성
//     Marine(int x, int y, int _default_damage);

//     int attack();           // 데미지를 리턴한다.
//     void be_attacked(int damage_earn);  //입는 데미지
//     void move(int x, int y);// 새로운 위치

//     void show_status();     //상태를 보여준다.
// };

// Marine::Marine() : _hp(50), _CoordX(0), _CoordY(0), _default_damage(5), _isDead(false) {}

// Marine::Marine(int x, int y)
//     : _CoordX(x), _CoordY(y), _hp(50), _default_damage(5), _isDead(false) {}

// Marine::Marine(int x, int y, int default_damage)
//     :   _CoordX(x),
//         _CoordY(y),
//         _hp(50),
//         _default_damage(default_damage),
//         _isDead(false) {}

// void Marine::move(int x, int y) {
//     _CoordX = x;
//     _CoordY = y;
// }

// int Marine::attack() { return _default_damage; }
// void Marine::be_attacked(int damage_earn) {
//     _hp -= damage_earn;
//     if (_hp <= 0) _isDead = true;
// }
// void Marine::show_status() {
//     std::cout << " *** Marine *** " << std::endl;
//     std::cout << " Location : ( " << _CoordX << " , " << _CoordY << " ) " 
//         << std::endl;
//     std::cout << " HP : " << _hp << std::endl;    
// }

// int main() {
//     Marine marine1(2, 3, 10);
//     Marine marine2(3, 5, 10);

//     marine1.show_status();
//     marine2.show_status();

//     std::cout << std::endl << "마린 1 이 마린 2를 공격! " << std::endl;
//     marine2.be_attacked(marine1.attack());

//     marine1.show_status();
//     marine2.show_status();
// }


//--------------------------------------
//생성된 총 `Marine` 수 세기 (static 변수)

// #include <iostream>

// class Marine {
//     static int _TotalMarineNum;

//     int _hp;                // 마린 체력
//     int _CoordX, _CoordY;   // 마린 위치
//     bool _isDead;

//     const int _default_damage;   //기본 공격력

//     public:
//     Marine();               // 기본 생성자
//     Marine(int x, int y);   // x, y 좌표에 마린 생성
//     Marine(int x, int y, int _default_damage);

//     int attack();           // 데미지를 리턴한다.
//     void be_attacked(int damage_earn);  //입는 데미지
//     void move(int x, int y);// 새로운 위치

//     void show_status();     //상태를 보여준다.
//     ~Marine() { _TotalMarineNum--; }
// };
// int Marine::_TotalMarineNum = 0;

// Marine::Marine() : _hp(50), _CoordX(0), _CoordY(0), _default_damage(5), _isDead(false) 
//     { _TotalMarineNum++; }

// Marine::Marine(int x, int y)
//     : _CoordX(x), _CoordY(y), _hp(50), _default_damage(5), _isDead(false) 
//     { _TotalMarineNum++; }

// Marine::Marine(int x, int y, int default_damage)
//     :   _CoordX(x),
//         _CoordY(y),
//         _hp(50),
//         _default_damage(default_damage),
//         _isDead(false) {
//             _TotalMarineNum++;
//         }

// void Marine::move(int x, int y) {
//     _CoordX = x;
//     _CoordY = y;
// }

// int Marine::attack() { return _default_damage; }
// void Marine::be_attacked(int damage_earn) {
//     _hp -= damage_earn;
//     if (_hp <= 0) _isDead = true;
// }
// void Marine::show_status() {
//     std::cout << " *** Marine *** " << std::endl;
//     std::cout << " Location : ( " << _CoordX << " , " << _CoordY << " ) " 
//         << std::endl;
//     std::cout << " HP : " << _hp << std::endl;
//     std::cout << " 현재 총 마린 수 : " << _TotalMarineNum << std::endl;    
// }

// void create_marine() {
//     Marine marine3 (10, 10, 4);
//     marine3.show_status();
// }

// int main() {
//     Marine marine1(2, 3, 5);
//     marine1.show_status();

//     Marine marine2(3, 5, 10);
//     marine2.show_status();

//     create_marine();

//     std::cout << std::endl << "마린 1 이 마린 2를 공격! " << std::endl;
//     marine2.be_attacked(marine1.attack());

//     marine1.show_status();
//     marine2.show_status();
// }

//---------------------------------------------
//static 함수 사용

//static 함수
// #include <iostream>

// class Marine {
// 	static int total_marine_num;
//   const static int i = 0;

//   int hp;                // 마린 체력
//   int coord_x, coord_y;  // 마린 위치
//   bool is_dead;

//   const int default_damage;  // 기본 공격력

//  public:
//   Marine();              // 기본 생성자
//   Marine(int x, int y);  // x, y 좌표에 마린 생성
//   Marine(int x, int y, int default_damage);

//   int attack();                       // 데미지를 리턴한다.
//   void be_attacked(int damage_earn);  // 입는 데미지
//   void move(int x, int y);            // 새로운 위치

//   void show_status();  // 상태를 보여준다.
// 	static void show_total_marine();
// 	~Marine() { total_marine_num--; }
// };

// int Marine::total_marine_num = 0;
// void Marine::show_total_marine() {
//   std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
// }
// Marine::Marine()
//     : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
//   total_marine_num++;
// }

// Marine::Marine(int x, int y)
//     : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
//   total_marine_num++;
// }

// Marine::Marine(int x, int y, int default_damage)
//     : coord_x(x),
//       coord_y(y),
//       hp(50),
//       default_damage(default_damage),
//       is_dead(false) {
//   total_marine_num++;
// }

// void Marine::move(int x, int y) {
//   coord_x = x;
//   coord_y = y;
// }
// int Marine::attack() { return default_damage; }
// void Marine::be_attacked(int damage_earn) {
//   hp -= damage_earn;
//   if (hp <= 0) is_dead = true;
// }
// void Marine::show_status() {
//   std::cout << " *** Marine *** " << std::endl;
//   std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
//             << std::endl;
//   std::cout << " HP : " << hp << std::endl;
//   std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
// }

// void create_marine() {
//   Marine marine3(10, 10, 4);
//   Marine::show_total_marine();
// }

// int main() {
//   Marine marine1(2, 3, 5);
//   Marine::show_total_marine();

//   Marine marine2(3, 5, 10);
//   Marine::show_total_marine();

//   create_marine();

//   std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
//   marine2.be_attacked(marine1.attack());

//   marine1.show_status();
//   marine2.show_status();
// }

//----------------------------------------------
//this 자기 자신을 가리키는 포인터 this

// #include <iostream>

// class Marine {
//   static int total_marine_num;
//   const static int i = 0;

//   int hp;                // 마린 체력
//   int coord_x, coord_y;  // 마린 위치
//   bool is_dead;

//   const int default_damage;  // 기본 공격력

//  public:
//   Marine();              // 기본 생성자
//   Marine(int x, int y);  // x, y 좌표에 마린 생성
//   Marine(int x, int y, int default_damage);

//   int attack();                          // 데미지를 리턴한다.
//   Marine& be_attacked(int damage_earn);  // 입는 데미지
//   void move(int x, int y);               // 새로운 위치

//   void show_status();  // 상태를 보여준다.
//   static void show_total_marine();
//   ~Marine() { total_marine_num--; }
// };

// int Marine::total_marine_num = 0;
// void Marine::show_total_marine() {
//   std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
// }

// Marine::Marine()
//     : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
//   total_marine_num++;
// }

// Marine::Marine(int x, int y)
//     : coord_x(x),
//       coord_y(y),
//       hp(50),

//       default_damage(5),
//       is_dead(false) {
//   total_marine_num++;
// }

// Marine::Marine(int x, int y, int default_damage)
//     : coord_x(x),
//       coord_y(y),
//       hp(50),
//       default_damage(default_damage),
//       is_dead(false) {
//   total_marine_num++;
// }

// void Marine::move(int x, int y) {
//   coord_x = x;
//   coord_y = y;
// }
// int Marine::attack() { return default_damage; }
// Marine& Marine::be_attacked(int damage_earn) {
//     hp -= damage_earn;
//     if (hp <= 0) is_dead = true;

//     return *this;
// }
// void Marine::show_status() {
//   std::cout << " *** Marine *** " << std::endl;
//   std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
//             << std::endl;
//   std::cout << " HP : " << hp << std::endl;
//   std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
// }
// int main() {
//   Marine marine1(2, 3, 5);
//   marine1.show_status();

//   Marine marine2(3, 5, 10);
//   marine2.show_status();

//   std::cout << std::endl << "마린 1 이 마린 2 를 두 번 공격! " << std::endl;
//   marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

//   marine1.show_status();
//   marine2.show_status();
// }


//---------------------------------------
//레퍼런스를 리턴하는 함수

// #include <iostream>

// class A {
//     int x;

//     public:
//     A(int c) : x(c) {} // 생성자

//     int &access_x() { return x; }
//     int get_x() { return x; }
//     void show_x() { std::cout << x << std::endl;}
// };

// int main() {
//     A a(5);
//     a.show_x();

//     int& c = a.access_x();
//     c = 4;
//     a.show_x();

//     int d = a.access_x();
//     d = 3;
//     a.show_x();

//     //아래는 오류
//     //int& e = a.get_x();
//     // e = 2;
//     // a.show_x();

//     int f = a.get_x();
//     f = 1;
//     a. show_x();

// }

//-------------------------------------------------
//const 함수 (상수 멤버 함수)
#include <iostream>

class Marine {
  static int total_marine_num;
  const static int i = 0;

  int hp;                // 마린 체력
  int coord_x, coord_y;  // 마린 위치
  bool is_dead;

  const int default_damage;  // 기본 공격력

 public:
  Marine();              // 기본 생성자
  Marine(int x, int y);  // x, y 좌표에 마린 생성
  Marine(int x, int y, int default_damage);

  int attack() const;                    // 데미지를 리턴한다.
  Marine& be_attacked(int damage_earn);  // 입는 데미지
  void move(int x, int y);               // 새로운 위치

  void show_status();  // 상태를 보여준다.
  static void show_total_marine();
  ~Marine() { total_marine_num--; }
};

int Marine::total_marine_num = 0;

void Marine::show_total_marine() {
  std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}

Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y)
    : coord_x(x),
      coord_y(y),
      hp(50),

      default_damage(5),
      is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false) {
  total_marine_num++;
}

void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}

int Marine::attack() const { return default_damage; }
Marine& Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;

  return *this;
}

void Marine::show_status() {
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
  std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

int main() {
  Marine marine1(2, 3, 5);
  marine1.show_status();

  Marine marine2(3, 5, 10);
  marine2.show_status();

  std::cout << std::endl << "마린 1 이 마린 2 를 두 번 공격! " << std::endl;
  marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}
