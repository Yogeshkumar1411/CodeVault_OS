#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
	int p1[2]; // C -> P
	int p2[2]; // P -> r
	printf("Main\n");
	if( pipe(p1) == -1) { return 5;}
	if( pipe(p2) == -1) { return 6;}
	int id = fork();
	if(id == 0){
		//Child process
		close(p1[0]);
		close(p2[1]);
		int x;
		if(read(p2[0],&x,sizeof(x)) == -1) { return 1;}
	//	close(p2[0]);
		printf("Received = %d\n",x);
		 
		x=x+3;
		
		if(write(p1[1],&x,sizeof(x)) == -1) { return 2;}
	//	close(p1[1]);
		printf("Wrote = %d\n",x);
		close(p1[1]);
		close(p2[0]);
		
	}
	else{
		//Parent preocess
		close(p2[0]);
		close(p1[1]);
		int y=10;
		if(write(p2[1],&y,sizeof(y)) == -1) { return 3;}
	//	close(p2[1]);
		printf("Written = %d\n",y);
		if(read(p1[0],&y,sizeof(y)) == -1) { return 4;}
	//	close(p1[0]);
		printf("Result = %d\n",y);
		close(p2[1]);
                close(p1[0]);
//		wait(NULL);
	}
}
