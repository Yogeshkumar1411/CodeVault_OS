#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
int x=0;
void handle_sigusr1(int sig)
{
	if(x==0)
	{
		printf("Need to enter the answer...\n");
	}
}




int main()
{
	int pid = fork();
	if(pid == -1)
	{
		return 1;
	}

	if(pid == 0)
	{
		
		//Child process
		while(1)
		{
		sleep(5);
		kill(getppid(),SIGUSR1);
		}
	}
	else{
		struct sigaction sa;
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &handle_sigusr1;
		sigaction(SIGUSR1,&sa,NULL);

		//Parent process
		printf("The result of 3 * 5:");
		scanf("%d",&x);
		if(x==15)
		{
			printf("Right\n");
		}
		else
		{
			printf("Wrong\n");
		}
	}
}
