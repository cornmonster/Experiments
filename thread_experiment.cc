#include <pthread.h>
#include <iostream>
#include <vector>
#include <malloc.h>

/*
 * This program is a simple version of multi-thread
 * bubble sort. I only create one thread and pass a
 * vector<int> to it.
 */
typedef struct {
	int *nums;
	int length;
} thread_arg;

void *bubbleSort(void * arg)
{
	thread_arg *p = (thread_arg*)arg;
	bool changed = true;
	int swap;
	while(changed)
	{
		changed = false;
		for(int i=0; i < 10-1; i++)
		{
			if(p->nums[i] > p->nums[i+1])
			{
				swap = p->nums[i];
				p->nums[i] = p->nums[i+1];
				p->nums[i+1] = swap;
				changed = true;
			}
		}
	}
}
int main()
{
	thread_arg *arg;
	int *a;
	int l = 10;
	a = (int *)malloc(10*sizeof(int));
	for(int i=0; i < 10; i++)
	{
		a[i] = 10-i;
	}
	for(int i=0; i < 10; i++)
	{
		printf("%d\n", a[i]);
	}

	arg->nums = a;
	arg->length = l;

	pthread_t t;
	pthread_create(&t, NULL, bubbleSort, arg);
	pthread_join(t, NULL);

	for(int i=0; i < 10; i++)
	{
		printf("%d\n", a[i]);
	}
}
