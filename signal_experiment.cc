#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

using namespace std;
static volatile int keepRunning = 1;
void INThandler(int dummy)
{
	keepRunning = 0;
}

void *worker(void *arg)
{
	int thread_id = *(int *)arg;
	int counter = 0;
	while(keepRunning)
	{
		fprintf(stderr, "[%d] %d\r\n", thread_id, counter);
		counter++;
	}
	fprintf(stderr, "[%d] Thread Ends.\r\n", thread_id);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	signal(SIGINT, INThandler);
	pthread_t threads[5];
	int threads_id[5];
	for(int i=0; i < 5; i++)
	{
		threads_id[i] = i;
		pthread_create(&threads[i], NULL, worker, (void *)(threads_id+i));
	}
	for(int i=0; i < 5; i++)
		pthread_join(threads[i], NULL);
	return 0;
}