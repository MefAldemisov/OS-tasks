/* *
* Author: Bogdanova Alina BS18-04
* Date: 28.08.19
* Description: Program, that prints right-side-up trinagle
* of height n and width 2n-1
* (n - command line parameter)
*/

#include<stdio.h>

int n; //height of that figure
int flag; // type of figure to print

void print_sequence(char ch, int t){
	/*Prints char 'ch' 't' times*/
	for (int i=0; i<t; i++)
		putc(ch, stdout);
}

void right_side_layer_printer(int height){
	/*Prints the next layer of the triangle*/

	int max_stars = 2 * n - 1; // max possible amount of stars

	int spaces = max_stars / 2 - height + 1; // amount of spaces to print
	int stars = height * 2 - 1; // amount of stars to ptint
		
	print_sequence(' ', spaces);
	print_sequence('*', stars);
	putc('\n', stdout);
}


void layer_printer(int height){
	/**Outputs the next layer of the image*/
	switch (flag){
		case 0: // square
			print_sequence('*', n);
			putc('\n', stdout);
			break;
		case 1: // right triangle
			print_sequence('*', height);
			putc('\n', stdout);
			break;
		case 2: // right side triangle
			right_side_layer_printer(height);
			break;
	}

}


int main(int argc, char * argv[]){
	// read the data from user:

	if (argc < 3){
		printf("Not enough arguments, please enter the height and the figure type\nas a command line parameters");
		return 0;
	}

	sscanf(argv[1], "%d", &n);
	sscanf(argv[2], "%d", &flag);

	if(n < 0){
		printf("Height has incorrect value, it should be greater, then 0");
		return 0;
	}

	if (flag < 0 || flag > 3){
		printf("Flag has incorrect value, it should be in range [0, 2]");
		return 0;
	}

	for(int height=1; height<=n; height++)
		layer_printer(height);

	if(flag == 1){
		for(int height=1; height<=n; height++){
			print_sequence('*', n - height);
			putc('\n', stdout);
		}
	}

	return 0;
}