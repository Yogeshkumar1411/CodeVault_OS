#include<stdio.h>
#include<pthread.h>

int x;
int lock=0;

void *routine(){
	int i;
	if(lock==1)
	{
	
		while(lock==1);
	}
	if(lock==0)
	{
		lock=1;
	for(i=0;i<100000;i++)
	{
		x++;
	}
		lock=0;
	}
}

int main()
{
	pthread_t p1,p2;
	if(pthread_create(&p1, NULL, &routine, NULL)){
		return 1;
	}
	if(pthread_create(&p2, NULL, &routine, NULL)){
		return 2;
	}
	if(pthread_join(p1,NULL)){
		return 3;
	}
	if(pthread_join(p2,NULL)){
		return 4;
	}

	printf("x = %d\n",x);
	return 0;
}

