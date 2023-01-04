#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	int id = fork();
	if(id == 0)
	{
		printf("First child\n");
	}

	int id1 = fork();

	if(id1 == 0)
	{
		printf("Second child\n");
	}

	printf("Parent\n");
}
