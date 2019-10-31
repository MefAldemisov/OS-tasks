#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

#define CONTENT "This is a nice day"

int main() {
	char* src = CONTENT;
	struct stat buf;
	// open
	int file = open("ex1.txt", O_RDWR, 0600);
	if (file < 1){
		fprintf(stderr, "File cannot be opened\n");
		return 1;
	}
	//  go to the end of file
	if (lseek(file, strlen(src)-1, SEEK_SET) == -1) {
		fprintf(stderr, "Cannot move inside output file\n");
		return 1;
	}
	//  get length
	if (fstat(file, &buf) < 0){
		fprintf(stderr, "Cannot get stat\n");
		return 1;
	}
	size_t size = buf.st_size;

	// to remove everything from file
	if (write(file, "", 1) == -1) {
		fprintf(stderr, "Cannot write to the output file\n");
		return 1;
	}

	char* dest = mmap(NULL, strlen(src), PROT_READ|PROT_WRITE, MAP_SHARED, file, 0);
	if (dest == (caddr_t) -1){
		fprintf(stderr, "Mapping problems\n");
		return 1;
	}

	if (size > strlen(src)) {
		char temp[size];
		for(int i=0; i<size; i++){
			temp[i] = '\0';
		} 
		memcpy(temp, src, strlen(src));
		memcpy(dest, temp, size);
	}else{
		memcpy(dest, src, strlen(src));
	}
	return 0;
}