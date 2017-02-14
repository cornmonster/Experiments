#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
	int listen_fd = socket(PF_INET, SOCK_STREAM, 0);
	struct sockaddr_in serverAddr;
	bzero(&serverAddr, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = htons(INADDR_ANY);
	serverAddr.sin_port = 10000;
	bind(listen_fd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

	listen(listen_fd, 10);
	while(true)
	{
		struct sockaddr_in clientaddr;
		socklen_t clientaddrlen = sizeof(clientaddr);
		int comm_fd = accept(listen_fd, (struct sockaddr *)&clientaddr, &clientaddrlen);
		fprintf(stderr, "connection from %s\n", inet_ntoa(clientaddr.sin_addr));	
	}
}
