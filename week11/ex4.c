#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

int main() {
	// open the files
	int input_file = open("ex1.txt", O_RDWR, 0600);
	int output_file = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0600);
	if (input_file < 1 || output_file < 1) {
		fprintf(stderr, "Files cannot be opened\n");
		return 1;
	}
	// get the length of the input
	struct stat input_stat;
	if (fstat(input_file, &input_stat) < 0){
		fprintf(stderr, "Cannot get stat\n");
		return 1;
	}
	size_t i_size = input_stat.st_size;

	// get length of the output
	struct stat output_stat;
	if (fstat(output_file, &output_stat) < 0){
		fprintf(stderr, "Cannot get stat\n");
		return 1;
	}
	size_t o_size = output_stat.st_size;

	// to remove everything from file
	if (lseek(output_file, i_size, SEEK_SET) == -1) {
		fprintf(stderr, "Cannot move inside output file\n");
		return 1;
	}

	if (write(output_file, "", 1) == -1) {
		fprintf(stderr, "Cannot write to the output file\n");
		return 1;
	}
	// mapping itself
	char* src = mmap(NULL, i_size, PROT_READ|PROT_WRITE, MAP_SHARED, input_file, 0);
	char* dest = mmap(NULL, i_size, PROT_READ|PROT_WRITE, MAP_SHARED, output_file, 0);
	if (src == (caddr_t) -1 || dest == (caddr_t) -1) {
		fprintf(stderr, "Mapping problems\n");
		return 1;
	}
	// if file is not empty
	if (o_size > i_size) {
		char temp[o_size];
		for(int i=0; i<o_size; i++){
			temp[i] = '\0';
		} 
		memcpy(temp, src, i_size);
		memcpy(dest, temp, o_size);
	} else {
		memcpy(dest, src, i_size);
	}

	return 0;
}