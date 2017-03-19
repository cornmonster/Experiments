#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
	int sock = socket(PF_INET, SOCK_DGRAM, 0);

	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htons(INADDR_ANY);
	servaddr.sin_port = htons(10000);
	bind(sock, (struct sockaddr*)&servaddr, sizeof(servaddr));

	while(true) {
		struct sockaddr_in src;
		socklen_t srclen = sizeof(src);
		char buf[100];
		int rlen = recvfrom(sock, buf, sizeof(buf)-1, 0, (struct sockaddr*)&src, &srclen);
		buf[rlen] = 0;

		printf("Echoing [%s] to %s\n", buf, inet_ntoa(src.sin_addr));
		sendto(sock, buf, rlen, 0, (struct sockaddr*)&src, sizeof(src));
	}
}	