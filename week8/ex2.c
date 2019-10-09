#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include <string.h>
#define STEP_SIZE 10

int main(){
	for(int i=0; i<10; i++){
		sleep(1);
		void* p = malloc(STEP_SIZE*1024*1024);
		memset(p, 0, STEP_SIZE*1024*1024);
	}
}