#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	for(int i = 0; i<10; i++)
	{
		if (i>6) exit(EXIT_SUCCESS);
		printf("%d\n",i);
	}
	return 0;
}
