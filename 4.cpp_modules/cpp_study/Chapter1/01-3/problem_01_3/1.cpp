
#include <iostream>

int BoxVolume(int length, int width, int height);
int BoxVolume(int length, int width);
int BoxVolume(int length);
int BoxVolume();

int main()
{
    std::cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << std::endl;
    std::cout << "[5, 5, D] : " << BoxVolume(5, 5) << std::endl;
    std::cout << "[7, D, D] : " << BoxVolume(7) << std::endl;
    std::cout << "[D, D, D] : " << BoxVolume() << std::endl;

    return 0;
}

int BoxVolume(int length, int width, int height)
{
    return length * width * height;
}


int BoxVolume(int length, int width)
{
    return length * width * 2;
}

int BoxVolume(int length)
{
    return length * 2 * 2;
}


int BoxVolume()
{
    return 2 * 2 * 2;
}