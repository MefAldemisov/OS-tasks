#include<stdlib.h>
#include<stdio.h>

#define MAX_CHARS 100

int main(){
	char command[MAX_CHARS+2];
	char c;
	int i;
	printf("Enter the command not greater then %d chars long:\n", MAX_CHARS);
	while(((c=getchar())!='\n') && i<MAX_CHARS)
		command[i++] = c;
	command[i++]=38;// add '&' ad the end
	printf("%s\n", command);
	system(command);
}