#include <iostream>

int main()
{
	char name[100];
	char lang[200];

	std::cout << "�̸��� �����Դϱ�? ";
	std::cin >> name;

	std::cout << "�����ϴ� ���α׷��� ����?";
	std::cin >> lang;

	std::cout << "�� �̸��� " << name << "�Դϴ�." << std::endl;
	std::cout << "���� �����ϴ� ���� " << lang << "�Դϴ�." << std::endl;
	return 0;
}
