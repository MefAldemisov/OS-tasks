/*
* Author: Alina Bogdanova BS18-04
* Date: 25.09.19
* Description: a program that forks a child
* process, waits for 10 seconds and then
* sends a SIGTERM signal to the child
* Child process runs an infinite loop
* and print “I’m alive” every second
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> 
#include<signal.h> 


#define BUFF_SIZE 100

int main(){
	
	int pid;

	if(pid=fork()){
		// child
		while(1){
			printf("I'm available\n");
			sleep(1);
		}
	}else{
		// parent
		sleep(10);
		kill(pid, SIGTERM);
	}
	return 0;
}

/*
OUTPUT:
I'm available
I'm available
I'm available
I'm available
I'm available
I'm available
I'm available
I'm available
I'm available
I'm available
fish: “./ex5” terminated by signal SIGTERM (Polite quit request)	
*/