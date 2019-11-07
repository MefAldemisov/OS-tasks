/**
* Description: Implement tee using I/O system calls. By default, tee
* overwrites any existing file with the given name.
* Implement the -a command-line option (tee -a file),
* which causes tee to append text to the end of a file if it
* already exists
*/
#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <fcntl.h> 
#include <sys/stat.h>

off_t get_length_of_file(int file) {
	struct stat statistics;
	if (fstat(file, &statistics) < 0) {
		return -1;
	}
	return (int)statistics.st_size;
}

char input_get_char() {
	char ch;
	if (read(STDIN_FILENO, &ch, 1)==0){
		return EOF;
	}
	return ch;
}

int main(int argc, char* argv[]) {
	// how to do it without buffer? 
	// read char - append char
	// TODO
	// 1. Get length of file using 'stat'
	// 2. while c = (input_get_char()) != EOF:
	// 3.	Lseek with length of file + input_char_index++
	// 		write(c)		

	// TODO error handling + reading from argv
	if(argc < 2)
		return 0;

	char c;
	char* file_name;
	for(int i=1; i<argc; i++) {
		file_name = argv[i];
		int file = open(file_name, O_RDWR | O_CREAT, S_IRWXU|S_IRWXG|S_IRWXO);

		off_t length = get_length_of_file(file);
		while((c=input_get_char()) != EOF) {
			lseek (file, length++ - 1, SEEK_CUR); 
			write (file, &c, 1); 
		}
		close(file);
	}
	return 0; 
} 
