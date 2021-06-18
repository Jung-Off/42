#include <stdio.h>

#define RED 	"\x1b[31m"
#define GREEN 	"\x1b[32m"
#define YELLOW 	"\x1b[33m"
#define BLUE 	"\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN	"\x1b[36m"
#define RESET 	"\x1b[0m"



int main()
{
	//style #2

	printf(RED "this is RED!\n");
	printf(GREEN "this is green!\n");
	printf(YELLOW "this is yellow!\n");
	printf(BLUE "this is blue!\n");
	printf(MAGENTA "this is magenta!\n");
	printf(CYAN "this is cyan!\n");
	printf("this is no reset!\n");
	printf(RESET "this is reset!\n");

	//style #1
	printf(RED "this is RED!\n" RESET);
}
