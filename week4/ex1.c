#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 

int main() {
	int id;
	int n;
	if(id = fork()){
		int n;

		printf("Hello from parent [%d - %d]\n", getpid(), n);
	}else{
		int n;		
		printf("Hello from child [%d - %d]\n", getpid(), n);
	}
	return 0;
}