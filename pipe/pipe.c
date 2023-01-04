#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
//#include<fnctl.h>
#include<unistd.h>
int main()
{
	int fd[2];
	//fd[0]=write
	//fd[1]=read
	if(pipe(fd) == -1)
	{
		printf("Error while creating a pipe\n");
		return 1;
	}
	int id = fork();
	if(id == 0)
	{
		int x;
		close(fd[0]);
		printf("Enter the number: ");
		scanf("%d",&x);
		write(fd[1],&x,sizeof(int));
		close(fd[1]);
	}
	else{
		int y;
		close(fd[1]);
		read(fd[0],&y,sizeof(int));
		close(fd[0]);
		printf("The y is = %d\n",y+3);
	}
}

