#include <stdio.h>
#include <unistd.h>

int main(void)
{
	for(int i = 0; i < 10; ++i)
	{
		printf("1초마다 문자열 출력\n");
		usleep(1000 * 1000);
	}
}
