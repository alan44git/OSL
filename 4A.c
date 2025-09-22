#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define BUFFER_SIZE 5
#define MAX_IT 20
int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int count = 0;
sem_t empty;
sem_t full;
void* producer(void* arg) {
int item = 0;
for (int i = 0; i < MAX_IT; i++) {
//int item = rand() % 100;
sem_wait(&empty);
buffer[in] = item;
in = (in + 1) % BUFFER_SIZE;
count++;
printf("Producer produced: %d | Buffer count: %d\n", item, count);
sem_post(&full);
item++;
usleep(100000);
}
pthread_exit(NULL);
}
void* consumer(void* arg) {
for (int i = 0; i < MAX_IT; i++) {
sem_wait(&full);
int item = buffer[out];
out = (out + 1) % BUFFER_SIZE;
count--;
printf("Consumer consumed: %d | Buffer count: %d\n", item, count);
sem_post(&empty);
usleep(150000);
}
pthread_exit(NULL);

}
int main() {
pthread_t prod_thread, cons_thread;
srand(time(NULL));
sem_init(&empty, 0, BUFFER_SIZE);
sem_init(&full, 0, 0);
pthread_create(&prod_thread, NULL, producer, NULL);
pthread_create(&cons_thread, NULL, consumer, NULL);
pthread_join(prod_thread, NULL);
pthread_join(cons_thread, NULL);
printf("Production and consumption complete.\n");
return 0;
}
