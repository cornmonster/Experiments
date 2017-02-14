#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int sockfd = socket(PF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		fprintf(stderr, "Can't open socket.\n");
		exit(1);
	}

	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(10000);
	inet_pton(AF_INET, "127.0.0.1", &(servaddr.sin_addr));
	bool isConnceted = connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	if(isConnceted != -1)
	{
		fprintf(stderr, "Connected to local host.\n");
		while(true);
	}
	else
	{
		fprintf(stderr, "Connection fails.\n");
		exit(1);
	}
}
