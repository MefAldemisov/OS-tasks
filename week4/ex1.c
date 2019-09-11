/**
* Author: Alina Bogdanova BS18-04
* Date: 11.09.2019
* Description: a program that declares a variable
* n, forks a new process and prints “Hello
* from parent [PID - n]” and “Hello from
* child [PID - n]” from parent and child
* processes respectively. 
*
* ex1.sh - file, that runs ex1.c compiled to ex1 10 times
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 

int main() {
	int id;
	int n;
	if(id = fork()){
		printf("Hello from parent [%d - %d]\n", getpid(), n);
	}else{	
		printf("Hello from child [%d - %d]\n", getpid(), n);
	}
	return 0;
}