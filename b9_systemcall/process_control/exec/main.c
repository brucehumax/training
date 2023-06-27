#include <stdio.h>
#include <unistd.h>

char *sys_argv[] = {"ls","-l","-a","-h"};

void execl_demo()
{
	printf("Run command ls -lah after 2 seconds\n");
	sleep(2);
	execl("/bin/ls",*sys_argv, *(sys_argv+1), *(sys_argv+2), *(sys_argv+3), NULL);
}

int main(int argc, char *argv[])
{
	execl_demo();
	return 0;
}


