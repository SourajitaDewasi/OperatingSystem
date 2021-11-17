#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>


pthread_mutex_t mutex;
sem_t wrt;

int count = 1;
int countreader = 0;


void *Reader(void *R)
{   
    pthread_mutex_lock(&mutex);
    countreader++;
    if(countreader == 1) {
        sem_wait(&wrt); 
    }
    pthread_mutex_unlock(&mutex);
    printf("Reader %d: read count as %d\n",*((int *)R),count);

    pthread_mutex_lock(&mutex);
    countreader--;
    if(countreader == 0) {
        sem_post(&wrt); 
    }
    pthread_mutex_unlock(&mutex);
}


void *Writer(void *W)
{   
    sem_wait(&wrt);
    count = count+1;
    printf("Writer %d edit count at %d\n",(*((int *)W)),count);
    sem_post(&wrt);

}


int main()
{   

    pthread_t read[5],write[6];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt,0,1);

    int a[10] = {0,1,2,3,4,5}; 
    for(int i = 0; i < 5; i++) {
        pthread_create(&read[i], NULL, (void *)Reader, (void *)&a[i]);
    }
    for(int i = 0; i < 6; i++) {
        pthread_create(&write[i], NULL, (void *)Writer, (void *)&a[i]);
    }
    for(int i = 0; i < 2; i++) {
        pthread_join(read[i], NULL);
    }
    for(int i = 2; i >= 0; i--) {
        pthread_join(write[i], NULL);
    }
    for(int i = 2; i < 4; i++) {
        pthread_join(read[i], NULL);
    }
    for(int i = 3; i < 6; i++) {
        pthread_join(write[i], NULL);
    }
    for(int i = 4; i < 5; i++) {
        pthread_join(read[i], NULL);
    }sem_destroy(&wrt);
    pthread_mutex_destroy(&mutex);
    

    return 0;
    
}