#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int num = 1;

void* thread(void *vargp)
{
    int currentThreadID = *(int*)(vargp);
    //make the
    pthread_t tID1, tID2;
    int cID1 = 2*currentThreadID+1;
    int cID2 = 2*currentThreadID+2;
    
    if(cID1 > num)
    {
        printf("Thread %d done\n", *(int*)(vargp));
        return NULL;
    }
    
    pthread_create(&tID1, NULL, thread, &cID1);
    pthread_create(&tID2, NULL, thread, &cID2);
    
    pthread_join(tID1, NULL);
    pthread_join(tID2, NULL);
    return NULL;
}

int main(int argc, char* argv[])
{
    int shift = atoi(argv[1]);
    num <<= shift;
    num-=2;
    pthread_t tID1, tID2;
    int cID1 = 1, cID2 = 2;
    
    if(num > 0)
    {
        pthread_create(&tID1, NULL, thread, &cID1);
    }
    pthread_join(tID1, NULL);
    printf("Thread 1 done\n");
    
    if(num > 0)
    {
        pthread_create(&tID2, NULL, thread, &cID2);
    }
    pthread_join(tID2, NULL);
    printf("Thread 2 done\n");
    printf("Thread 0 done\n"); //main is thread 0
    exit(0);
}