#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<sys/wait.h>
int main(void)
{
	int upPipe[2];
	int downPipe[2];
	pipe(upPipe);
	pipe(downPipe);
	pid_t pid = fork();
	if(pid < 0)
	{
		// This means fork() failed. We should send the error msg to
		// the std out and exit the program. 
		fprintf(stderr, "FORK FAILED!\n");
		exit(1);
	}
	else if(pid == 0) 
	{
		// This means fork() succeed. Now we are in subprocess.
		close(upPipe[0]);	// The read end of upPipe is not used by subprocess, close it
		close(downPipe[1]);	// The write end of downPipe is not used by subprocess, close it
	
		const char *msg = "Hello world!";
		char buffer[200];

		read(downPipe[0], buffer, sizeof(buffer));
		printf("Child process received: %s\n", buffer);

		write(upPipe[1], msg, strlen(msg) + 1);
		printf("Child process sent: Hello world!\n");
		exit(0);	
	}
	else 
	{
		// This means fork() succeed. Now we are in father process.
		close(downPipe[0]);	// The read end of downPipe is not used by father process
		close(upPipe[1]);	// The write end of upPipe is not used by father process
		
		const char *msg = "Can you hear me?";
		char buffer[200];
		
		write(downPipe[1], msg, strlen(msg) + 1);
		printf("Message sent.\n");
		
		wait(NULL);

		read(upPipe[0], buffer, sizeof(buffer));
		printf("Message received from subprocess: %s\n", buffer);
		exit(0);
	}
}
		
