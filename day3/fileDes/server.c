#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1024

int main(int argc, char **argv)
{
	int server_sockfd, client_sockfd;
	int state, client_len;
	pid_t pid;
	struct sockaddr_un clientaddr, serveraddr;
	char buff[MAXLINE];

	if (argc != 2) {
		printf("Usage: %s [socket file name]\n", argv[0]);
		printf("example  : %s /tmp/mysocket/n", argv[0]);
		exit(0);
	}
	if (access(argv[1], F_OK) == 0) {
		unlink(argv[1]);
	}
	client_len = sizeof(clientaddr);
	if ((server_sockfd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
		perror("socket error : ");
		exit(0);
	}
	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sun_family = AF_UNIX;
	strcpy(serveraddr.sun_path, argv[1]);

	
	state = bind(server_sockfd, (struct sockaddr *)&serveraddr,
			sizeof(serveraddr));
	if (state == -1) {
		perror("bind error : ");
		exit(0);
	}
	
	state = listen(server_sockfd, 5);
	if (state == -1) {
		perror("listen error : ");
		exit(0);
	}
	
	while(1) {
		client_sockfd = accept(server_sockfd, (struct sockaddr *)&clientaddr, &client_len);
		pid = fork();
		if (pid == 0) {
			if (client_sockfd == -1) {
				perror("Accept error : ");
				exit(0);
			}
			while(1) {
				memset(buff, 0x00, MAXLINE);
				if(read(client_sockfd, buff, MAXLINE) <= 0) {
					close(client_sockfd);
					exit(0);
				}
				printf("From client -> %s", buff);
				write(client_sockfd, buff, strlen(buff));
			}
		}
	}
	close(client_sockfd);
}


