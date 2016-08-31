#include <stdio.h>
#define READ 0
#define WRITE 1

int main()
{
	int fd[2];
	int pid, ret;
	char buf[128];

	ret = pipe(fd);
	if(ret==-1) puts("pipe() returned error");
	pid=fork();
	if(pid==-1) puts("fork() returned error");

	if(pid==0) {
		close(fd[WRITE]);
		read(fd[READ], buf, sizeof(buf));
		puts(buf);
		printf("Child process [%d] termination\n", getpid());
		close(fd[READ]);
	}
	else {
		close(fd[READ]);
		write(fd[WRITE], "Hello, child process", sizeof(buf));
		printf("Parent Process [%d] termination\n", getpid());
		close(fd[WRITE]);
		sleep(1);
	}

	return 0;
}

