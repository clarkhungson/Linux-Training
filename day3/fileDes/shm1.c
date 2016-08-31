#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define FIRST 0
#define SECOND 1

int main()
{
	int shmid;
	int *shm_addr = NULL;
	int buf[2];
	int skey = 1204;
	
	shmid = shmget(skey, sizeof(buf), 0666|IPC_CREAT);
	if(shmid == -1)
		puts("shmget is fail\n");
	
	shm_addr = (int *)shmat(shmid, 0, 0);
	if (shm_addr == NULL) {
		puts("shmat is fail\n");
		return -1;
	}
	shm_addr[FIRST] = getpid();
	sleep(1);
	printf("My pid [%d], Your pid [%d]\n",
		shm_addr[FIRST], shm_addr[SECOND]);
	
	return 0;
}

