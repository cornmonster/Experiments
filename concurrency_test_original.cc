#include <stdio.h>
#include <pthread.h>

const int MAX = 1000000;
volatile int count = 0;

void *test(void *arg) 
{  
    for (int j=0; j<MAX; j++)    
        count = count + 1;    
    return NULL;
}
int main(void) 
{  
    pthread_t thread0, thread1;  
    pthread_create(&thread0, NULL, test, NULL);
    pthread_create(&thread1, NULL, test, NULL);
    pthread_join(thread0, NULL);
    pthread_join(thread1, NULL);
    printf("count=%d\n", count);    return 0;
}
