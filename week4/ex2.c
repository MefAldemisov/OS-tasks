/**
* Author: Alina Bogdanova BS18-04
* Date: 11.09.2019
* Description: a program that calls fork() in a loop
* 3 times and sleeps for 5 seconds
*
* command to print the tree: $ pstree $! (in a bash shell)
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 

#define SLEEP_TIME 5 	// time to sleap in seconds
#define LOOPS 5			

int main() {
	for(int i=0; i<LOOPS; i++){
		fork();
		sleep(SLEEP_TIME);
	}
	return 0;
}

/**
OUTPUT of  pstree $!:
ex2─┬─ex2─┬─ex2─┬─ex2─┬─ex2───ex2
    │     │     │     └─ex2
    │     │     ├─ex2───ex2
    │     │     └─ex2
    │     ├─ex2─┬─ex2───ex2
    │     │     └─ex2
    │     ├─ex2───ex2
    │     └─ex2
    ├─ex2─┬─ex2─┬─ex2───ex2
    │     │     └─ex2
    │     ├─ex2───ex2
    │     └─ex2
    ├─ex2─┬─ex2───ex2
    │     └─ex2
    ├─ex2───ex2
    └─ex2
*/