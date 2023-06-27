#include <stdio.h>
#include <unistd.h>

int main(int argc, char *arg[])
{
	pid_t retvl;
	retvl = fork();
	if (retvl == 0)
	{
		printf("This is child process\n");
		printf("Child PID: %d\n",getpid());
 	} else if (retvl > 0) {
		printf("This is parent process\n");
		printf("Parent PID: %d\n",getpid());
	} else {
		printf("fork() unsuccessful\n");
	}
	return 0;
}	


