/*
* Author: Alina Bogdanova BS18-04
* Date: 25.09.19
* Description: a program that a program that 
* intercepts SIGINT signal (Ctrl+C) and notifies user
*/

#include<stdlib.h>
#include<stdio.h>
#include<signal.h> 


void catch_the_signal(int sig){
	printf("SIGINT cauched\n");
	exit(0); // to terminate process
}

int main(){
	signal(SIGINT, catch_the_signal);
	while(1)
		;
	return 0;
}	