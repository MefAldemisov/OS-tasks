#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 

// $ pstree $! - to show the tree (useful)
int main() {
	for(int i=0; i<3; i++){
		fork();
		sleep(5);
	}
	return 0;
}