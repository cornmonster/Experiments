/*
	I wrote this program to figure out how to use
	getopt(). 
*/
#include<iostream>
#include<unistd.h>
#include<stdio.h>

int main(int argc, char * argv[])
{
	// use this varible to save the return value 
	// form getopt().
	int option = -1;

	// set opterr to 0 ot prevent getopt() sending
	// error msg to stderr.
	opterr = 0;
	
	while((option = getopt(argc, argv, ":tn:")) != -1)
	{
		switch(option)
		{
			case 'n':
				printf("case n\n");
				printf("N = %s\n", optarg);
				break;
			case 't':
				printf("case t\n");
				printf("optarg: %s\n", optarg);
				printf("optopt: %c\n", optopt);
				break;
			case '?':
				printf("case ?\n");
				printf("optarg: %s\n", optarg);
				printf("optopt: %c\n", optopt);		
				break;
			default:
				exit(1);
		}
	}
	printf("argc: %d\n", argc);
	printf("optind: %d\n", optind);
	printf("argv:\n");
	for(int i=0; i < argc; i++) 
	{
		printf("%s", argv[i]);
		if(i != argc-1)
			printf("->");
		else
			printf("\n");
	}
	return 0;
}
