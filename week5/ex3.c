/**
* Author: Alina Bogdanova BS18-04
* Date: 18.09.19
* Description: a producer-consumer problem that uses threads
* and shares a common buffer without usage of
* semaphores or any other synchronization primitives to
* guard the shared data structures 
* */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS  2
#define INIT_VALUE 100
#define COUNT_LIMIT 200

int count = INIT_VALUE;

int can_add = 1;
int can_sub = 1;


void *increment_count() {
    while (1) {
        count++;
        can_sub = 1;      
        if (count == COUNT_LIMIT) {
            can_add = 0;    
        }
        while(can_add!=1){
            ;
        }
    }
}

void *decrement_count() {
    while(1) {
        count--;
        can_add = 1;
        if (count == 0) {
            can_sub = 0;
        }
        while(can_sub!=1){
            ;
        }
    }
}

void *printer() {
    while(1){
        printf("%d\n", count);
        sleep(60);
    }
}

int main (){
    pthread_t threads[3];
 
    pthread_create(&threads[0], NULL, increment_count, NULL);
    pthread_create(&threads[1], NULL, decrement_count, NULL);
    pthread_create(&threads[2], NULL, printer, NULL);

    for (int i=0; i<2; i++) {
        pthread_join(threads[i], NULL);
    }
    printf ("Main(): Waited on %d  threads. Done.\n", 2);
    pthread_exit(NULL);

} 