#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <pthread.h>

#define BUF_SIZE 8

int pfd[2];
char buf[BUF_SIZE];
pthread_mutex_t pipe_mutex1, pipe_mutex2;

static void *handle_thr1(void *args)
{
	pthread_mutex_lock(&pipe_mutex1);
	for (int i = 0; i<5; i++) {write(pfd[1], "Thread 1", strlen("Thread 1"));}
	pthread_mutex_unlock(&pipe_mutex1);
}

static void *handle_thr2(void *args)
{
	pthread_mutex_lock(&pipe_mutex2);
	for (int i = 0; i<4; i++) {write(pfd[1], "Thread 2", strlen("Thread 2"));}
        pthread_mutex_unlock(&pipe_mutex2);
}

int main(int argc, char *arg[])
{
	pid_t retvl;
	if (pipe(pfd) < 0) {
		printf("pipe unsucessfully\n");
	}
	pthread_mutex_init(&pipe_mutex1, NULL);
	pthread_mutex_init(&pipe_mutex2, NULL);

	retvl = fork();
	if (retvl == 0)
	{
		printf("This is child process\n");
		printf("Child PID: %d\n",getpid());
		close(pfd[1]);
		int res;
		while ((res = read(pfd[0], buf, BUF_SIZE)) > 0)
		{
			printf("%s\n", buf);
		}
		
		if(res == -1)
		{
			printf("Read from pipe fail\n");
		} else if (res == 0) {
			printf("Pipe terminated normally\n");
		}
		close(pfd[0]);
 	} else if (retvl > 0) {
		close(pfd[0]);
		pthread_t thread_id[2];
		pthread_create(&(thread_id[0]), NULL, &handle_thr1, NULL);
		pthread_create(&(thread_id[1]), NULL, &handle_thr2, NULL);
		printf("This is parent process\n");
		printf("Parent PID: %d\n",getpid());
		pthread_join(thread_id[0], NULL);
		pthread_join(thread_id[1], NULL);
		close(pfd[1]);
		wait(NULL);
		pthread_mutex_destroy(&pipe_mutex1);
		pthread_mutex_destroy(&pipe_mutex2);
		exit(EXIT_SUCCESS);
	} else {
		printf("fork() unsuccessful\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}	


