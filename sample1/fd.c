#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int fd = open("my1.txt", O_WRONLY);
	int fd1 = open("my.txt", O_WRONLY);
	printf("fd  = %d   fd1 = %d \n",fd,fd1);
}
