#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#include<fcntl.h>

int main()
{
	if(mkfifo("myfifo1",0777)== -1)
	{
		if(errno!=EEXIST)
		{
			printf("Could not creayte fifo file\n");
			return 1;
		}
	}
	printf("Opening...\n");
	int fd = open("myfifo1", O_WRONLY);
	printf("Opened...\n");
	char x[]="Yogesh\n";
	printf("Writting..\n");
	if(write(fd,&x,sizeof(x)) == -1)
	{
		return 2;
	}
	printf("Written..\n");
	close(fd);
	printf("Closed...\n");
	
	char p[50];
	fd = open("myfifo1",O_RDONLY);
	if(read(fd,p,sizeof(p)) == -1)
	{
		printf("Error\n");
		return 3;
	}
	close(fd);
	printf("\n\n\n From Read = %s\n",p);

	return 0;
}
