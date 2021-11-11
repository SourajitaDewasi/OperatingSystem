#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

#define MaxItems 3
#define Shelf 3 

sem_t empty;
sem_t full;
int sin = 0;
int sout = 0;
int buffer[Shelf];
pthread_mutex_t mutex;

void *Producer(void *P)
{   
    int item=1;
    for(int i = 0; i < 3; i++) {
        item = item+1; 
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[sin] = item;
        printf("Produced Item %d at %d\n", buffer[sin],sin);
        sin = (sin+1)%Shelf;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}
void *Consumer(void *C)
{   
    for(int i = 0; i < 3; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[sout];
        printf("Consumed Item %d from %d\n",item, sout);
        sout = (sout+1)%Shelf;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main()
{   

    pthread_t pro[3],con[3];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty,0,3);
    sem_init(&full,0,0);

    int a[3] = {0,1,2}; 

    for(int i = 0; i < 3; i++) {
        pthread_create(&pro[i], NULL, (void *)Producer, (void *)&a[i]);
    }
    for(int i = 0; i < 3; i++) {
        pthread_create(&con[i], NULL, (void *)Consumer, (void *)&a[i]);
    }

    for(int i = 0; i < 3; i++) {
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < 3; i++) {
        pthread_join(con[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
    
}