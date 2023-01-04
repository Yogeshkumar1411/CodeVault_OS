#include<stdio.h>
int main()
{
	int a=10;
	int id = fork();
	if(id==0)
	{
		printf("Child process..\n");
		sleep(3);
		printf("a = %d\n",a*10);
		sleep(5);
		printf("End child..\n");
	}
	else
	{
		printf("Parent process ...\n");
		sleep(10);
		printf("a = %d\n",a*5);
		sleep(5);
		printf("End parent..\n");
	}
}
