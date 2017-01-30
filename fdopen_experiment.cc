#include <iostream>
#include <unistd.h>
#include <string>
using namespace std;
int main()
{
	int mypipe[2];
	pipe(mypipe);
	pid_t pid;
	
	if((pid = fork()) == 0)
	{
		close(mypipe[0]);
		FILE *fwrite;
		int a = 19930707;
		const char *msg = to_string(a).c_str();
		
		fwrite = fdopen(mypipe[1], "w");
		fprintf(fwrite, "%s\n", msg);
		fprintf(stderr, "msg sent\n");
		exit(0);
	}
	else
	{
		close(mypipe[1]);
		FILE *fread;
		char msg[50];
		fread = fdopen(mypipe[0], "r");
		fgets(msg, 10, fread);
		fprintf(stderr, "%d\n", atoi(msg));
	}
	return 0;
}

	
