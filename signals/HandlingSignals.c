#include<stdio.h>
#include<signal.h>

void handle_sigtstp(int sig)
{
	printf("Stop not allowed\n");
}

void handle_sigcont(int sig)
{
	printf("Input number : ");
	fflush(stdout);

}
int main()
{
	struct sigaction sa,sa1;
	sa.sa_handler = &handle_sigtstp;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGTSTP,&sa,NULL);// one of the methods
	
//	signal(SIGTSTP,handle_sigtstp); // another method

	sa1.sa_handler = &handle_sigcont;
	sa1.sa_flags = SA_RESTART;
	sigaction(SIGCONT,&sa1,NULL);

	int x;
	printf("Input number: ");
	scanf("%d",&x);
	printf("Result %d * 5 = %d\n",x,x*5);
}
