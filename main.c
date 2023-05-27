#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *threadFunction(void *arg)
{
    char *str = (char *)arg;
    printf("%s\n", str);
}

int main()
{
    pthread_t myThread; // hold thread id
    int rc;             // hold return code

    // creat thread
    rc = pthread_create(&myThread, NULL, threadFunction, "arrgument");
    if (rc != 0)
    {
        printf("Error creating thread.\n");
        exit(-1);
    }

    // join thread
    rc = pthread_join(myThread, NULL);
    if (rc != 0)
    {
        printf("Error joining thread.\n");
        exit(-1);
    }

    return 0;
}