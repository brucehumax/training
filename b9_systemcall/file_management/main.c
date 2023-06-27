#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd;
	char *read_buf = (char*)malloc(100*sizeof(char));
	fd = open("test.txt", O_RDWR|O_CREAT, 0667);
	if (fd == -1)
	{	
		printf("Open file failed!\n");
	}
	//write(fd, "Who r u ?", strlen("Who r u ?"));
	//sleep(5);
	read(fd, read_buf, 100);
	write(fd, "Who r u ?", strlen("Who r u ?"));
	printf("%s\n",read_buf);
	free(read_buf);
	close(fd);
	return 0; 
}
