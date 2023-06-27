#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	pid_t retvl;
	retvl = fork();
	if (retvl > 0) 
	{
		printf("This is parent process\n");
		printf("Parent pid: %d\n",getpid());
	} else if (retvl ==0) {
		printf("This is child process\n");
		printf("Child pid: %d, Parent pid: %d\n", getpid(), getppid());
	} else {
		printf("fork() fail!\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}
