/**
* Author: Alina Bogdanova BS18-04
* Date: 18.09.19
* Description: a program that runs N threads: 
* each thread outputs its number and some text, then exit
* Main program informs about thread creation
* Program is fixed to force the order to be strictly
* thread 1 created, thread 1 prints message, thread
* 1 exits and so on 
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
  
#define N 8

void *thread_function(void *vargp) { 
    /** Method that is going to be executed by threads*/
    printf("Thread ID: %d\n",(int) pthread_self()); 
    pthread_exit(NULL);
    // thread finishes automaticly, when it has finished the method
} 
  
int main() { 
    pthread_t tid; // id of thread to be executed
    for (int i = 0; i < N; i++) {
        pthread_create(&tid, NULL, thread_function, NULL); 
        printf("Thread %d created\n", (int) tid);
        pthread_join(tid, NULL); // added line
    }
  	printf("Finish\n");
  	return 0; 
} 

/*
Initial output:
```
Thread -1833060608 created
Thread -1841453312 created
Thread ID: -1841453312
Thread -1849846016 created
Thread ID: -1833060608
Thread -1858238720 created
Finish
Thread ID: -1858238720
Thread ID: -1849846016
```
(unordered execution)

Configured output:
```
Thread -905648384 created
Thread ID: -905648384
Thread -905648384 created
Thread ID: -905648384
Thread -905648384 created
Thread ID: -905648384
Thread -905648384 created
Thread ID: -905648384
Finish
```
(the same id is caused to the finishing of the)

*/