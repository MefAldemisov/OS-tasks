/**
* Author: Alina Bogdanova BS18-04
* Date: 11.09.2019
* Description: simplistic shell:
* programm that reads user input and 
* is able to run a command without parameters,
* such as pwd, ls, top, pstree and so on,
* Using a `system()` command 
*/

#include<stdlib.h>
#include<stdio.h>

#define MAX_CHARS 10

int main(){
	char command[MAX_CHARS];
	printf("Enter the command not greater then %d chars long:\n", MAX_CHARS);
	scanf("%s", command);
	system(command);
}