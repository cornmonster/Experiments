#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

using namespace std;

int main() {
	const char* myWords = "hello world!";
	int sock = socket(PF_INET, SOCK_DGRAM, 0);
  	if(sock < 0) {
  		fprintf(stderr, "-ERR Cannot open socket\n");
  		exit(1);
  	}
  	struct sockaddr_in dest;
  	bzero(&dest, sizeof(dest));
  	dest.sin_family = AF_INET;
  	dest.sin_port = htons(10000);
  	inet_pton(AF_INET, "127.0.0.1", &(dest.sin_addr));
  	sendto(sock, myWords, strlen(myWords), 0, (struct sockaddr*)&dest, sizeof(dest));

  	char buf[100];
  	struct sockaddr_in src;
  	socklen_t srcSize = sizeof(src);
  	int rlen = recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr*)&src, &srcSize);
  	buf[rlen] = 0;
  	printf("%s", buf);

  	close(sock);
  	return 0;
}