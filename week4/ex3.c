#include<stdlib.h>
#include<stdio.h>

#define MAX_CHARS 10

int main(){
	char command[MAX_CHARS];
	printf("Enter the command not greater then %d chars long:\n", MAX_CHARS);
	scanf("%s", command);
	system(command);
}