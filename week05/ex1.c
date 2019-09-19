#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 7

int thread_id[NUM_THREADS];

void * PrintHello(int i) {
    printf("Hello, I am %d !\n", i);
    pthread_exit(NULL);
}
int main(int argc, char * argv[]) {
    int rc, i;
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&thread_id[i], NULL, PrintHello, i);
        printf("Thread %d was created\n", i);
        if (i % 3 == 0)
            sleep(1);
        pthread_join(thread_id[i],NULL);
        printf("Thread %d exits\n", i);
    }
    pthread_exit(NULL);
}
