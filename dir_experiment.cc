#include <iostream>
#include <dirent.h>
#include <stdlib.h>

/*
	This program can output all the files and sub-directories
	of a given directory
*/
int main(int argc, char *argv[])
{
	/*
		process the arguments
	*/
	if(argc != 2) {
		fprintf(stderr, "ERR: Invalid arguments.\n");
		exit(1);
	}
	DIR *dir;
	struct dirent *dp;
	int counter = 0;
	if((dir = opendir(argv[1])) == NULL) {
		fprintf(stderr, "ERR: Invalid arguments.\n");
		exit(1);
	}
	while((dp = readdir(dir)) != NULL) {
		printf("%s\n", dp->d_name);
		counter++;
	}
	printf("====================\n");
	printf("Number of files: %d\n", counter);
	(void)closedir(dir);
	return 0;
}