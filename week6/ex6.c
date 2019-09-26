#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h> 
#include<sys/wait.h>

#define BUFF_SIZE 4

// int counter=0;

void catch_stop(int i){

	printf("SECOND: I didn't want to die!!!\tNO!!!...\n");
	exit(0);
}


void second_process(){
	signal(SIGHUP, catch_stop);
	while(1){
		printf("I'm second process (%d)! I'm active!\n", getpid());
	}
}


void first_process(int processes_0) {
	// wait for pid of the second
	int pid_2, size;
	printf("FIRST: (I'm %d) Wait for pid_2 from\n", getpid());
	while((size=read(processes_0, &pid_2, BUFF_SIZE)) < 0 ){  // system read: (to, to_exact, size)
		; //busy waiting
	}
	close(processes_0);
	printf("FIRST: pid_2 recieved, it is %d. Kill it.\n", pid_2);
	// send SIGSTOP to child 2
	sleep(0.2);
	kill(pid_2, SIGSTOP);
	printf("FIRST: killed\n");
	exit(0);
}

void root_proces(int processes_1, int pid_second){
	// send pid of the second process to the first process
	int status;

	printf("ROOT: write pid_2 (%d)\n", pid_second);
	sleep(0.2);
	write(processes_1, &pid_second, BUFF_SIZE); // system write: (from, value, size)
	close(processes_1);
	printf("ROOT: (my pid is %d) pid_2 written. Wait.\n", getpid());
	// wait for state changes in the second process
	
	waitpid(pid_second-1, &status, 0);
	printf("ROOT: I'm done\n");
	exit(0);
}

int main(){

	int pids[3], pid;
	int processes[2];	
	if(pipe(processes) < 0){
		return(0);
	}
	pids[0] = getpid();
	pid=fork();
	if(pids[0]!=getpid()){
		pids[1] = getpid();
		// child 1 process
		first_process(processes[0]);
	}else{
		// parent
		pid=fork();
		if(pids[0]!=getpid()){
			// child 2 process
			second_process();
		}else{
			// main process
			root_proces(processes[1], getpid()+2);
		}
	}
	return 0;
}

/*
OUTPUT:
ROOT: write pid_2 (8962)
ROOT: (my pid is 8960) pid_2 written. Wait.
FIRST: (I'm 8961) Wait for pid_2 from
FIRST: pid_2 recieved, it is 8962. Kill it.
I'm second process (8962)! I'm active!
I'm second process (8962)! I'm active!
I'm second process (8962)! I'm active!
I'm second process (8962)! I'm active!
I'm second process (8962)! I'm active!
I'm second process (8962)! I'm active!
I'm second process (8962)! I'm active!
I'm second process (8962)! I'm active!
FIRST: killed
ROOT: I'm done
SECOND: I didn't want to die!!!	NO!!!...
*/