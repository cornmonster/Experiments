Hello world,
This is a repository consisting of files I wrote to practice
things I learned in school.

Here is the description for each file:

1. pipe_experiment.cc
	A program that uses a pair of pipes (an up pipe and a down pipe). I just
	want to know how pipe works.
2. getopt_experiment.cc
	A program that uses getopt() to resolve arguments. I want to know how 
	getopt() works.
3. bubbleSort.cc
	A simple bubble sort program. I wrote this because I need to implement a
	multi-process bubble sort.
4. fdopen_experiment.cc
	A program to figure out how to use fdopen to convert a pipe to a file 
	descriptor. Using file descriptor, communication between processes can
	be much easier.
5. to_string_experiment.cc
	Use std::string::to_string() to convert a long long int to a string.
6. concurrency_test_original.cc
	Interesting program, have different result on different platform. This 
	program uses two threads to update a global variable, because different
	platform have different scheduler, it outputs a integer between 2 and 
	2000000 on macos, and outputs 2000000 all the time on ubuntu.
