#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *t_function(void *param)
{
    for (int i = 1;i < 10; i++)
    {
        usleep(1000 * 1000 * 2); //2초 대기
        printf("%s: ", (char *)param);
        printf("쓰레드 함수 실행 중..%d/5\n",i);
    }
        printf("쓰레드 함수 종료\n");
        return (void *)2147483647;
}

void *t_function2(void *param)
{
    for (int i = 1;i < 5; i++)
    {
        usleep(1000 * 1000 * 2); //2초 대기
        printf("%s: ", (char *)param);
        printf("쓰레드 함수 실행 중..%d/5\n",i);
    }
        printf("쓰레드 함수 종료\n");
        return (void *)2147483647;
}

int main()
{
    pthread_t p_thread1;
    pthread_t p_thread2;
    int thr_id1;
    int thr_id2;

	printf("쓰레드 create\n");

//	pthread_detach(p_thread1);
//	pthread_detach(p_thread2);
	//pthread_join(p_thread1, 0);
	//pthread_join(p_thread2, 0);
    thr_id1 = pthread_create(&p_thread1, NULL, t_function, "thread1");
    thr_id2 = pthread_create(&p_thread2, NULL, t_function2, "thread2");
    if (thr_id1 < 0 || thr_id2 < 0)
    {
        perror("thread create error : ");
        exit(0);
    }
 
//  pthread_detach(p_thread1);
//	pthread_detach(p_thread2);
//	pthread_join(p_thread1, 0);
	printf("\n\n");
	pthread_join(p_thread2, 0);

	for(int i = 0; i < 3; i ++)
	{
		printf("main 쓰레드 실행중 .. %d\n", i);
		usleep(1000 * 1000 * 2);
	}

//	pthread_detach(p_thread1);
//	pthread_detach(p_thread2);
//	pthread_join(p_thread1, 0);
//	pthread_join(p_thread2, 0);

    printf("main() 종료\n");
    return 0;
}
