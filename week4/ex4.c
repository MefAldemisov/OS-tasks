/**
* Author: Alina Bogdanova BS18-04
* Date: 11.09.2019
* Description: extend ex3.c to handle
* commands with parameters and running
* processes in background 
* 
* e.g. `ls -al`
*/

#include<stdlib.h>
#include<stdio.h>

#define MAX_CHARS 100

int main(){
	char command[MAX_CHARS+1]; // 1 additional char - for '&'
	// which is used to run the programm in background
	char c;
	int i;
	printf("Enter the command not greater then %d chars long:\n", MAX_CHARS);
	// read the line of input
	while(((c=getchar())!='\n') && i<MAX_CHARS)
		command[i++] = c;
	command[i++]=38; // add '&' ad the end
	system(command); // execute
}