#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_INODES 10
#define MAX_STR_LENGTH 100
unsigned int inods[MAX_INODES];
char inode_files[MAX_INODES][MAX_STR_LENGTH];
int length;

int inode_search(unsigned int inode){
	for(int i=0; i<MAX_INODES; i++){
		if(inods[i] == inode){
			return i;
		}
		if(i == length){
			length++;
			inods[i] = inode;
			return i;
		}
	}
}

void add_filenme(char file_name[MAX_STR_LENGTH], unsigned int inode){
	int index = inode_search(inode);
	char name[MAX_STR_LENGTH];
	strcpy(name, inode_files[index]);
	strcat(name, " ");
	strcat(name, file_name);
	strcpy(inode_files[index], name);
}

void print_result(){
	for(int i=0; i<length; i++){
		printf("Inode: %d, files:%s\n", inods[i], inode_files[i]);
		if(inods[i] == 0){
			break;
		}
	}
}

int main(){
	length = 0;
	char* dir_name = "./tmp";
	char file_name [MAX_STR_LENGTH];
	DIR* dirp = opendir(dir_name);
	struct dirent* dp;
	struct stat buf;
	int len;
	if (dirp == NULL) { 
		return (1); 
	}
	while ((dp = readdir(dirp)) != NULL) {
		strcpy(file_name, dir_name);
		strcat(file_name, "/");
		strcat(file_name, dp->d_name);
		stat(file_name, &buf);

		if(buf.st_nlink >= 2 && strlen(dp->d_name)>2){
			add_filenme(file_name, buf.st_ino);
		}
	}
	print_result();
	(void)closedir(dirp);
	return (0);
}