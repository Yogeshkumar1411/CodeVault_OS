#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int x=0;
void inc()
{
	int i;
	for(i=0;i<1000000;i++)
	{
		x++;
	}
}

int main()
{
	int id = fork();
	if(id==0)
	{
		sleep(5);
		inc();
	}
	else
	{
		inc();
	}
	int i,m=0;
	for(i=0;i<500;i++)
	{
		m++;
	}

	printf("m of %d = %d\n",id,m);
}	
