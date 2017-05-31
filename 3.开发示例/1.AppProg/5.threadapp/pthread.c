/* pthread.c */
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* �߳�һ */
void thread1(void)
{
	int i = 0;
	while(i++ < 6)
	{
		printf("This is pthread1.\n");
		if(i == 2)
			pthread_exit(0);
		sleep(2);
	}
}
/* �̶߳� */
void thread2(void)
{
	int i = 0;
	while(i++ < 3)
	{
		printf("This is pthread2.\n");
	}
	sleep(1);
	pthread_exit(0);
}
int main()
{
	pthread_t id1,id2;
	int ret;

	pthread_attr_t attr;
	/* ��ʼ���߳� */
	pthread_attr_init(&attr);
	/* �����̰߳����� */
	pthread_attr_setscope(&attr,PTHREAD_SCOPE_SYSTEM);
	/* �����̷߳������� */
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	/* �ֱ𴴽��߳�1��2 */
	ret = pthread_create(&id1,&attr,(void *)thread1,NULL);
	if(ret != 0)
	{
		printf("Create pthread1 error\n");
		exit(1);
	}
	ret = pthread_create(&id2,NULL,(void *)thread2,NULL);
	if(ret != 0)
	{
		printf("Create pthread2 error\n");
		exit(1);
	}
	/* �ȴ��߳̽��� */
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	return 0;
}
