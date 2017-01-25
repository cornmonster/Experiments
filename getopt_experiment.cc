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
	int option;

	// set opterr to 0 ot prevent getopt() sending
	// error msg to stderr.
	opterr = 0;
	
	while((option = getopt(argc, argv, "n:")) != -1)
	{
		
	}
}
