#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

#define OUTPUT "Hello"

int main() {
	char* str = OUTPUT; 									// string defined
	int length = strlen(str); 								// length of the buffer and the string
	char buffer[length]; 									// buffer created
	int buf_ind = setvbuf(stdout, buffer, _IOLBF, length); 	// stdout buffered
	for (int i=0; i<length; i++){							// cycle
		printf("%c", str[i]);								// output to the buffer (stdout)
		sleep(1);											// wait for a second
	}
	printf("\n");											// output the content of the buffer
	return 0;
}