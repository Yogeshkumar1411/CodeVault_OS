#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int id = fork();
	if(id == -1) { return 2;}
	if(id == 0){
		//Child process
		execv("/home/gopi/Documents/yogesh/os/sample/./exec",NULL);
	}
	else
	{
		//Parent process
		printf("\n\nExec executed\n");
	}
}
