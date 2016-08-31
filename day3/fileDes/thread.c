#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREAD 3

void *thread_func(void *thread_arg)
{
	int id;
	int i = 0;
	
	id = *((int *)thread_arg);
	while(1)
	{
		printf("%dth thread: %d\n", id, i);
		i++;
		if(i==5)
			return (void *)i;
		sleep(1);
	}
}
int main(int argc, char *argv[])
{
	pthread_t threads[NUM_THREAD];
	int thread_id;
	int status;
	int thread_arg[NUM_THREAD] = {0, 1, 2};
	int i = 0;

	for(i=0;i<NUM_THREAD;i++)
	{
		thread_id = pthread_create(&threads[i], NULL, thread_func, (void *)&thread_arg[i]);
		if(thread_id < 0)
		{
			perror("thread create error");
			exit(0);
		}
	}
	pthread_exit(NULL);

	return 0;
}

