#include<stdio.h>
#include<pthread.h>
pthread_mutex_t mutex;
void *routine(void *arg)
{
	pthread_mutex_lock(&mutex);
	printf("Got lock\n");
	sleep(2);
	pthread_mutex_unlock(&mutex);
}

int main()
{
	pthread_t th[4];
	pthread_mutex_init(&mutex,NULL);
	for(int i=0;i<4;i++)
	{
		if(pthread_create(&th[i],NULL,&routine,NULL) !=0){
				perror("Error at creating thread");
			}
	}

	for(int i=0;i<4;i++)
	{
		if(pthread_join(th[i],NULL) !=0){
			perror("Error at joining thread");
		}
	}
	pthread_mutex_destroy(&mutex);
	return 0;
}

