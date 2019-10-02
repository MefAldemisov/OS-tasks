#include <stdio.h>
#include <stdlib.h>

int main(){
	// prompting the N
	int N;
	printf("Enter the length of array:\n");
	scanf("%d", &N);
	// create array
	int* array = (int*) calloc(10, sizeof(int));
	// fill array
	for(int i=0; i<N; i++)
		array[i] = i;
	// print array
	for(int i=0; i<N; i++)
		printf("%d", array[i]);
	// deallocate memory
	free(array);
	return 0;
}