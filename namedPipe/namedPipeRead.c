#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	int fd = open("myfifo1",O_RDONLY);
	char ptr[50];
	if(read(fd,ptr,sizeof(ptr)) == -1)
	{
		return 1;
	}
	close(fd);
	printf("Copied data = %s\n",ptr);
	
	char *p="Bitsilica";
	int len = strlen(p);
	printf("Length = %d\n",len);
	fd = open("myfifo1",O_WRONLY);
	if(write(fd,p,len+1) == -1)
	{
		printf("Error\n");
		return 2;
	}
	close(fd);
}
