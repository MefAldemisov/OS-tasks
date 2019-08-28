/* *
* Author: Bogdanova ALina BS18-04
* Date: 28.08.19
* Description: reversing of the input numbers with a pointers
*/

#include<stdio.h>

void swap(int* a, int* b){
	/*Swapping of two integers*/
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int a, b;
	printf("Enter two numbers, separated by space:\n");
	scanf("%d %d", &a, &b);
	printf("Initial values:\na = %d\tb = %d\n", a, b);
	swap(&a, &b);
	printf("Swapped values:\na = %d\tb = %d", a, b);
	return 0;
}
