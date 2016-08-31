#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
        int pid;

        /* fork another process */
        pid = fork();
        if (pid < 0)    /* error occurred */
        {
                fprintf(stderr, "Fork Failed");
                exit(-1);
        }
        else if (pid == 0)      /* child process */
        {
                printf("I am child process\n");
                execl("/bin/ls", "ls", NULL);

        }
        else            /* parent process */
        {
                printf("I am parent process\n");
                wait(NULL); // wait until exit child process
                printf("Parent: Child Complete\n");
                exit(0);
        }
}

