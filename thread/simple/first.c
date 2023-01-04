#include<stdio.h>
#include<pthread.h>

void * routine(int a)
{
	int result = a*5;
	printf("Test from threads\n");
	sleep(5);
	printf("Result = %d\n",result);
	sleep(5);
	printf("Ending threads\n");
}

int main()
{
	pthread_t t1,t2;
	if(pthread_create(&t1, NULL, routine, 5))
       	{
		return 1;
	}
	if(pthread_create(&t2, NULL, routine, 4))
       	{
		return 2;
	}
	if(pthread_join(t1, NULL))
       	{
		return 3;
	}
	if(pthread_join(t2, NULL))
       	{
		return 4;
	}
	return 0;
}
