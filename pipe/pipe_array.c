#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>


int main()
{
	int fd[2];

	if(pipe(fd) == -1)
	{
		return 1;
	}
	
	int pid = fork();
	if(pid == -1)
	{
		return 2;
	}
	if(pid == 0)
	{
		printf("Wriing process...\n");
		close(fd[0]);
		int arr[]={1,2,3,4,5,6};
		int n=sizeof(arr)/sizeof(int);
		if(write(fd[1],&n,sizeof(int)) == -1){
			return 3;
		}
		printf("n = %d\n",n);
		if(write(fd[1],arr,sizeof(int)*n) == -1){
			return 4;
		}
		close(fd[1]);
		int i;
		printf("Array: ");
		for(i=0;i<n;i++)
		{
			printf("%d ",arr[i]);
		}
		printf("\nArray written\n");
	}
	else
	{
		printf("Reading process...\n");
		close(fd[1]);
		int n,arr[10];
		if(read(fd[0],&n,sizeof(int)) == -1){
			return 5;
		}
		if(read(fd[0],arr,sizeof(int)*n) == -1){
			return 6;
		}
		close(fd[0]);
		int i;
		int sum=0;
		for(i=0;i<n;i++)
		{
			sum=sum+arr[i];
		}
		printf("The sum is = %d\n",sum);
	}
}
