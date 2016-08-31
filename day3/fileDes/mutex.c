#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREAD 2

int ncount;	/* shared variable */
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *do_loop(void *thread_arg)
{
	int i;	
	for(i=0;i<10;i++) 
	{
		pthread_mutex_lock(&mutex);
		printf("loop1 : %d\n", ncount);
		ncount++;
		if(i == 10) return;
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}
void *do_loop2(void *thread_arg)
{
	int i;	
	for(i=0;i<10;i++) 
	{
		pthread_mutex_lock(&mutex);
		printf("loop2 : %d\n", ncount);
		ncount++;
		pthread_mutex_unlock(&mutex);
		sleep(2);
	}
}
int main(int argc, char *argv[])
{
	pthread_t threads[NUM_THREAD];
	int thread_id;
	int status;
	int i, a = 1;

	ncount = 0;

	thread_id = pthread_create(&threads[0], NULL, do_loop, (void *)&a);
	sleep(1);
	thread_id = pthread_create(&threads[1], NULL, do_loop2, (void *)&a);
	

	for(i=0;i<NUM_THREAD;i++)
	{
		pthread_join(threads[i], (void **)&status);
		printf("return thread %d: %d\n", i, status);
	}
	
	status = pthread_mutex_destroy(&mutex);
	printf("code = %d\n", status);
	
	return 0;
}

