/*
* Author: Alina Bogdanova BS18-04
* Date: 25.09.19
* Description: a program that declares signal
* handlers for SIGKILL, SIGSTOP and SIGUSR1
*/
#include<stdlib.h>
#include<stdio.h>
#include<signal.h> 


void catch_the_signal(int sig){
	switch(sig){
		case SIGINT:
			printf("SIGINT cauched\n");
			break;
		case SIGKILL:
			printf("SIGKILL cauched\n");
			break;
		case SIGSTOP:
			printf("SIGSTOP cauched\n");
			break;
		case SIGUSR1:
			printf("SIGUSR1 cauched\n");
			break;
		default:
			printf("Sgnal\n");
	}
	
	exit(0); // to terminate process
}

int main(){
	signal(SIGINT, catch_the_signal);
	signal(SIGKILL, catch_the_signal);
	signal(SIGSTOP, catch_the_signal);
	signal(SIGUSR1, catch_the_signal);

	while(1)
		;
	return 0;
}	

/*
OUTPUT:
>> kill -SIGUSR1 15501
SIGUSR1 cauched
Job 1, './ex4&' has ended 
>>
*/