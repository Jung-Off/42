
/*int gettimeofday(struct timeval *tv, struct timezone *tz);*/

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main()
{
	struct timeval startTime, endTime;
	double diffTime;

	gettimeofday(&startTime, NULL);
	
	for(int i = 0; i < 10; i++)
	{
		printf("%d 번째\n", i);
		usleep(1000 * 1000);
	}
	
	gettimeofday(&endTime, NULL);
	diffTime = endTime.tv_sec - startTime.tv_sec;
	double diff = (endTime.tv_usec - startTime.tv_usec);

	printf("%lf \n", diffTime);
	printf("%lf \n", diff);
	return 0;
}
