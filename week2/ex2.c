/**
* Author: Bogsanova Alina BS18-04
* Date: 28.08.19
* Description: reversing of the string
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_CHARS 10

int main(){
 	char * input = calloc(MAX_CHARS, sizeof(char)) ;
 	printf("Enter the string with %d chars at max:\n", MAX_CHARS);
 	scanf("%s", input);

 	printf("Reverse string:\n");
 	for(int i=strlen(input)-1; i>=0; i--)
 		putc(input[i], stdout);

 	free(input);
	return 0;
}