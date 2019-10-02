#include <stdio.h>
#include <stdlib.h>

int main(){
	char **s = (char**) malloc(sizeof(char**)); /*Allocate some memory*/
	char *foo = "Hello World";
	*s = foo;
	printf("s is %s\n", *s);
	s[0] = foo; /*The same, as in line 7*/
	printf("s[0] is %s\n", s[0]);
	return(0);	
}