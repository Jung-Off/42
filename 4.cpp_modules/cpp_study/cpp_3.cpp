// #include <iostream>

// int main() {
//     int *p = new int;
//     *p = 10;

//     std::cout << *p << std::endl;

//     delete p;
//     return 0;
// }


// #include <iostream>

// int main() {
// 	int a = 5;

// 	delete &a;

// 	return 0;
// }

//new로 배열 할당하기
// #include <iostream>

// int main() {
// 	int arr_size;
// 	std::cout << "array_size : ";
// 	std::cin >> arr_size;
// 	int *list = new int[arr_size];
// 	for (int i = 0; i < arr_size; i++) {
// 		std::cin >> list[i];
// 	}
// 	for (int i = 0; i < arr_size; i++) {
// 		std::cout << i << "th element of list : " << list[i] << std::endl;
// 	}
// 	delete[] list;
// 	return 0;
// }
// #include <iostream>

// int main()
// {
//     int a = 4;
//     {
// 	    std::cout << "외부의 변수 1 : " << a << std::endl;
// 	    int a = 3;
// 	    std::cout << "내부의 변수  : " << a << std::endl;
//     }
//     std::cout << "외부의 변수 2 : " << a << std::endl;
// }



// ---------------------------------------------------------
// #include <iostream>

// typedef struct Animal {
//     char name[30];
//     int age;
//     int health;
//     int food;
//     int clean;
// }   Animal;

// void create_animal(Animal *animal) {
//     std::cout << "동물의 이름? ";
//     std::cin >> animal->name;

//     std::cout << "동물의 나이? ";
//     std::cin >> animal->age;

//     animal->health = 100;
//     animal->food = 100;
//     animal->clean = 100;
// }

// void play(Animal *animal)
// {
//     animal->health += 10;
//     animal->food -= 20;
//     animal->clean -= 30;
// }

// void show_stat(Animal *animal)
// {
//     std::cout << animal->name << "의 상태" << std::endl;
//     std::cout << "나이      : "<< animal->age << std::endl;
//     std::cout << "체력      : " << animal->health << std::endl;
//     std::cout << "배부름     : " << animal->food << std::endl;
//     std::cout << "청결      : " << animal->clean << std::endl;
// }

// void animal_list_check(Animal *animal)
// {
//     std::cout << animal->name << std::endl;
//     std::cout << "나이  : " << animal->age << std::endl;
//     std::cout << "체력  : " << animal->health << std::endl;
//     std::cout << "배부름 : " << animal->food << std::endl;
//     std::cout << "청결  : " << animal->clean << std::endl;

// }

// void see_all(Animal **list, int animal_num)
// {
//     for (int i = 0; i != animal_num; i++) {
//             std::cout << "=======" << i << "======" << std::endl;
//             animal_list_check(list[i]);
//             std::cout << "==============" << std::endl;
//         }

// }

// void one_day_pass(Animal *animal)
// {
//     animal->health -= 10;
//     animal->food -= 30;
//     animal->clean -= 20;
// }

// int main() {
//     Animal *list[10];
//     int animal_num = 0;
//     int exit_c = 1;
//     Animal **copy_list = list;

//     while(exit_c) {
//         std::cout << "1. 동물 추가하기" << std::endl;
//         std::cout << "2. 놀기" << std::endl;
//         std::cout << "3. 상태 보기" << std::endl;
//         std::cout << "4. 전체 보기" << std::endl;
//         std::cout << "5. 종료" << std::endl;

//     int input;
//     std::cin >> input;

//     switch (input) {
//         int play_with; //동물 idx;
//         case 1:
//             list[animal_num] = new Animal;
//             std::cout << animal_num << std::endl;
//             create_animal(list[animal_num]);
//             //12까지 접근을 하는데 접근은 할 수 있다 뭐 이런건가
//             animal_num++;
//             break;
//         case 2:
//             std::cout << "누구랑 놀게? : ";
//             std::cin >> play_with;

//             if (play_with < animal_num) 
//                 play(list[play_with]);
//             break;
//         case 3:
//             std::cout << "누구껄 보게? : ";
//             std::cin >> play_with;
//             if (play_with < animal_num)
//                 show_stat(list[play_with]);
//             break;
//         case 4:
//             see_all(copy_list, animal_num);
//             break;
//         case 5:
//             std::cout << "=========종료======== "<< std::endl;
//             exit_c = 0;
//             break;
//     }
        
//         for (int i = 0; i != animal_num; i++) {
//             one_day_pass(list[i]);
//             //어떠한 행동 1,2,3 을 하면 다른 동물 들 모두가 이 작업을 한다.
//         }
//     }
//     for (int i = 0; i != animal_num; i++)
//     {
//         std::cout << "=========" << i << " delete ======== " << std::endl;
//         delete list[i];
//     }
//     //12번까지 추가하고 delete하니까 abort가 뜨긴한다
//     //10, 11번은 왜 안뜨지
// }

// ---------------------------------------------------------


#include <iostream>

typedef struct Animal {
    char name[30];
    int age;
    int health;
    int food;
    int clean;
}   Animal;

void create_animal(Animal *animal)
{
    std::cout << "동물의 이름? ";
    std::cin >> animal->name;

    std::cout << "동물의 나이? ";
    std::cin >> animal->age;

    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;
}

void play(Animal *animal) {
    animal->health += 10;
    animal->food -= 20;
    animal->clean -= 30;
}

void one_day_pass(Animal *animal)
{
    animal->health -= 10;
    animal->health -= 30;
    animal->clean -= 20;
}

void show_stat(Animal *animal)
{
    std::cout << animal->name << "의 상태" << std::endl;
    std::cout << "체력 : " << animal->health << std::endl;
    std::cout << "배부름 : " << animal->food << std::endl;
    std::cout << "청결 : " << animal->clean << std::endl;
}

int main() {
    Animal *list[10];
    int animal_num = 0;

    for(;;)
    {
        std::cout << "1. 동물 추가하기" << std::endl;
        std::cout << "2. 놀기 " << std::endl;
        std::cout << "3. 상태 보기 " << std::endl;

        int input;
        std::cin >> input;

        switch (input) {
            int play_with;
            case 1:
                list[animal_num] = new Animal;
                create_animal(list[animal_num]);
                animal_num++;
                break;
            case 2:
                std::cout << "누구랑 놀게? : ";
                std::cin >> play_with;
                if (play_with < animal_num) play(list[play_with]);
                break;
            case 3:
                std::cout << "누구껄 보게? : ";
                std::cin >> play_with;
                if (play_with < animal_num) show_stat(list[play_with]);
                break;
        }

        for (int i = 0; i != animal_num; i++)
            one_day_pass(list[i]);
    }
    for (int i = 0; i != animal_num; i++)
        delete list[i];

}

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
//         weight  += (inc / 3);
//     }
//     void view_start() {
//         std::cout << "이 동물의 food  : " << food << std::endl;
//         std::cout << "이 동물의 weight  : " << weight << std::endl;
//     }
// };

// int main() {
//     Animal animal;
//     animal.set_animal(100, 50);
//     animal.increase_food(30);

//     animal.view_start();
//     return 0;
// }