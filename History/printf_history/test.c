#include <stdio.h>
int main()
{	int i;
	i = printf("%0*.*d", -8, -3, 8321);
	printf("%d", i);
}
