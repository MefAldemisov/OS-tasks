#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 20
#define N 10

void* my_realloc(void *ptr, size_t size){
	if (ptr == NULL)
		return malloc(size);
	if (size == 0)
		free(ptr);
	else {
		void* result = (void*) malloc(size);
		memcpy(result, ptr, size);
		free(ptr);
		return(result);
	}
}

int main(){
	int* array = (int*) calloc(N, sizeof(int));
	for(int i=0; i<N; i++)
		array[i] = i;
	int* new_array = (int*) my_realloc(array, M*sizeof(int));
	for(int i=N; i<M; i++)
		new_array[i] = -1;
	for(int i=0; i<M; i++)
		printf("%d ", new_array[i]);
	free(new_array);
	return 0;
}