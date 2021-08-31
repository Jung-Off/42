
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//쓰레드 함수
void *thread_function(void *data)
{
	pthread_t tid;
	
	int i = 0;
	printf("\ttid : %x\n", tid);
	while(i < 10)
	{
		printf("\tnew thread : %d\n", i);
		i++;
		sleep(1);
	}
	return (NULL);
}

int main()
{
	pthread_t thread;
	pthread_create(&thread, NULL, thread_function, NULL);
	int i = 0;
	printf("tid : %x\n", pthread_self());
	while(i < 5)
	{
		printf("main : %d\n", i);
		i++;
		sleep(1);
	}
//	pthread_join(thread, NULL);
	return 0;
}	
