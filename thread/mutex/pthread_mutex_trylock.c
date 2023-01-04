//the multiple chefs are using the stove

#include<stdio.h>
#include<pthread.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
//chef = threads
//stove = shared data (+mutex)

pthread_mutex_t stoveMutex;
int stoveFuel = 100;

void *routine(void *arg){
	pthread_mutex_lock(&stoveMutex);
	int fuelNeeded = (rand()%30);

	if(stoveFuel - fuelNeeded < 0){
		printf("No more fuel... Going home\n");
	}
	else{
		stoveFuel-=fuelNeeded;
		printf("Fuel left %d\n",stoveFuel);
	}
	usleep(500000);
	pthread_mutex_unlock(&stoveMutex);


}


int main()
{
	srand(time(NULL));
	pthread_t th[10];
	pthread_mutex_init(&stoveMutex,NULL);
	for(int i=0;i<10;i++){
		if(pthread_create(&th[i], NULL, &routine, NULL) !=0){
			perror("Failed to create the thread\n");
		}
	}


	for(int i=0;i<10;i++){
		if(pthread_join(th[i], NULL) != 0){
			perror("Failed to join the thread\n");
		}
	}
	pthread_mutex_destroy(&stoveMutex);
}
