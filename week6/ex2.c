#include<stdio.h>
#include<stdlib.h>
#include <unistd.h> 
#include<string.h>

#define BUFF_SIZE 100

int main(){
	int fds[2], pid; // 0 - pass TO, 1 - pass FROM

	if(pipe(fds) < 0){ // creating a pipe with the pase on fib array
		exit(0);
	}

	if(pid=fork()){
		//child process
		char text[BUFF_SIZE];
		printf("Ener the text to pipe\n");
		scanf("%s", text);
		write(fds[1], text, BUFF_SIZE); // system write: (from, value, size)
		close(fds[1]);
	}else{
		// parent process
		char buffer[BUFF_SIZE];
		int result;
		while((result=read(fds[0], buffer, BUFF_SIZE)) == 0 ){  // system read: (to, to_exact, size)
			; //busy waiting
		}
		printf("The text is: %s", buffer);
		close(fds[0]);

	}
	return 0;
}