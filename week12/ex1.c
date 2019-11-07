/**
* Author: Alina Bogdanova BS18-04
* Date: 06.11.2019
* Description: generation and
display a random string of 20 symbols
using /dev/random file
*/

#include<stdlib.h>
#include<stdio.h>

#define MAX_LEN 20

int main(){
	// Yes, it is cheating
	char* cat_command = "cat /dev/random | head -c 20  > ex1.txt"; 
	if(system(cat_command)==-1){
		fprintf(stderr, "Error of '%s' command", cat_command);
		return 0;
	} 
}