// #include <iostream>

// int main() {
// 	int i;

// 	for (i = 0; i < 10; i++) {
// 	std::cout << i << std::endl;
// 	}
// 	return 0;
// }

// #include <iostream>

// int main() {
// 	int i;
// 	int sum = 0; //초기화 해주기

// 	for (i = 0; i <= 10; i++) {
// 		sum += i;
// 	}
// 	std::cout << "합은" << sum << std::endl;
// 	return 0;
// }

// #include <iostream>

// int main () {
// 	int lucky_number = 3;
// 	std::cout << "내 비밀의 수를 맞추어 보세요~" << std::endl;

// 	int user_input; //사용자의 입력

// 	while (1) {
// 		std::cout << "입력 : ";
// 		std::cin >> user_input;
// 		if (lucky_number == user_input) {
// 			std::cout << "맟추셨습니다~~" << std::endl;
// 			break;
// 		} else {
// 			std::cout << "다시 생각해보세요 ~" << std::endl;
// 		}
// 	}
// 	return 0;
// }

//switch 문 이용하기
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main () {
	int user_input;
	cout << "저의 정보를 표시합니다" << endl;
	cout << "1. 이름" << endl;
	cout << "2. 나이" << endl;
	cout << "3. 성별" << endl;
	cin >> user_input;

	switch (user_input) {
		case 1:
			cout << "Psi !" << endl;
			break;
		case 2:
			cout << "99살" << endl;
			break;
		case 3:
			cout << "남자" << endl;
            break;
		default:
			cout << "궁금한게 없군요!" << endl;
			break;
	}
	return 0;
}