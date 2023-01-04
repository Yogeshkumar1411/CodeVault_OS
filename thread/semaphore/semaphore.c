#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

#define THREAD_NUM 4

sem_t semaphore;


void* routine(void *args){
	sem_wait(&semaphore);
	printf("Hello from thread %d\n",*(int*)args);
	sleep(2);
	sem_post(&semaphore);
	free(args);
}

int main()
{
	pthread_t th[THREAD_NUM];
	sem_init(&semaphore,0,1);//second argument 0 for thread and 1 for process; third argument 1 for initializer
	int i;
	for(i=0;i<THREAD_NUM;i++){
		int *a=malloc(sizeof(int));
		*a=i;
		if(pthread_create(&th[i],NULL,&routine,a) !=0){
			perror("Failed to create thread\n");
		}
	}
	for(i=0;i<THREAD_NUM;i++){
		if(pthread_join(th[i],NULL) !=0){
                        perror("Failed to join thread\n");
                }
	}
	sem_destroy(&semaphore);
}
