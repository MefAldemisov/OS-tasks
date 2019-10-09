#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include <sys/resource.h>
#include <string.h>

#define STEP_SIZE 10

int main(){
	struct rusage usage;	
	for(int i=0; i < 10; i++){

		void* p = malloc(STEP_SIZE*1024*1024);
		memset(p, 0, STEP_SIZE*1024*1024);
		getrusage(RUSAGE_SELF, &usage);
		printf("%ld\n", usage.ru_maxrss);
		sleep(1);
	}
}