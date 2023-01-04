#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
	int arr[]={1,2,3,4,5,6,5};
	int fd[2];
	int arrSize = sizeof(arr)/sizeof(arr[0]);
	int Start,end;
	if(pipe(fd) == -1){
		return 1;
	}

	int id=fork();
	if(id ==-1){
		return 2;
	}

	if(id == 0)
	{
		Start=0;
		end=arrSize/2;
	}
	else
	{
		Start = arrSize/2;
		end=arrSize;
	}

	int sum=0;
	int i;
	for(i=Start;i<end;i++)
	{
		sum += arr[i];
	}

	printf("The sum of %d = %d\n",id,sum);

	if(id == 0){
		close(fd[0]);
		write(fd[1], &sum, sizeof(sum));
		close(fd[1]);
	}
	else
	{
		int sumFromChild;
		close(fd[1]);
		read(fd[0], &sumFromChild, sizeof(sumFromChild));
		close(fd[0]);

		sumFromChild = sum + sumFromChild;	
		printf("The sum from child = %d\n",sumFromChild);
		wait(NULL);
	}
	return 0;
}

