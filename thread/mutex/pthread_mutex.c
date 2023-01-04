#include<stdio.h>
#include<pthread.h>
int x;
pthread_mutex_t mutex;

void *routine(){
	int i;
	for(i=0;i<100000;i++){
		pthread_mutex_lock(&mutex);
		x++;
		pthread_mutex_unlock(&mutex);
	}
}

int main()
{
	pthread_t p1,p2;
	pthread_mutex_init(&mutex, NULL);
	if(pthread_create(&p1, NULL, &routine, NULL)){
		return 1;
	}
	if(pthread_create(&p2, NULL, &routine, NULL)){
		return 2;
	}
	if(pthread_join(p1, NULL)){
		return 3;
	}
	if(pthread_join(p2, NULL)){
		return 4;
	}
	
	pthread_mutex_destroy(&mutex);
	printf("x = %d\n",x);
	return 0;
}
