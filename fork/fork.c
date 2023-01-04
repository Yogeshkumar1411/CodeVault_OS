

//checking..............



#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
int sum()
{
	int a=10;
	int b=10;
	fork();
	printf("Sum = %d\n",a+b);
}
int sub()
{
	int a=10,b=5;
	printf("Sub = %d\n",a-b);
}
int main()
{
	sum();
	sub();
	while(1);
/*	int fd[]={2,3,4,5,5};
	pipe(fd);
	int i=0;
	int id = fork();
	if((id == 0)&&(i==1))
	{	
		//fd[0]=20;
		i=0;
		 for(int i=0;i<5;i++)
                {
                        printf("%d ",fd[i]);
                }
		printf("\n\nchild\n\n\n\n");
	}
	if((id !=0)&&(i==0))
	{
		i=1;
		fd[0]=20;
		for(int i=0;i<5;i++)
		{
			printf("%d ",fd[i]);
		}
		printf("\n\nParent\n\n\n\n\n");
	}*/
}
