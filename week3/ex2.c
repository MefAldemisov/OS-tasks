/**
* Author: ALina Bogdanova BS18-04
* Date: 04.09.19
* Description: function bubble_sort() which will
* accept an array of integers and sort it in
* place using Bubble sort algorithm
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int* first, int* second){
    /**
     * Swapping of two elements by the given adresses
    */
    int temp = *first;
    *first = *second;
    *second = temp;
}

int is_greater(int a, int b){
    /** Returns if the first value greater then the second*/
    return a > b;
}

int is_less(int a, int b){
    /** Returns if the first value is less then the second*/
    return a < b;
}

void bubble_sort(int* array, int length, int (*comparator) (int, int)) {
    /**
     * Required function.
     * Input parameter 'length' is a length of the input array.
     * It is required due to the fact, 
     * that we can't find out amount of elements in the array
     * in different way.
     * Comaparator - function pointer.
    */

   for(int i=0; i<length; i++){
       for(int j=0; j < length-i-1; j++){
           if (comparator(array[j], array[j+1]))
               swap(&array[j], &array[j+1]);
       }
   }

}

void get_input(int* length_pointer, int** array_pointer){
    /**
     * Gets the input from the user.
     * Length and array are passed by pointers
     * To prevent Segfalts
    */

    // Scan length
    printf("Enter the size of the array\n");
    scanf("%d", length_pointer);
    *array_pointer = (int*) calloc(*length_pointer, sizeof(int));

    // Scan array
    printf("Enter the elements of the array, separated by the space:\n");
    for(int i=0; i < *length_pointer; i++){
        scanf("%d", &(*array_pointer)[i]);
    }
}

void check(int* array, int length){
    /* Test function */
    for(int i=1; i<length; i++){
        if(array[i] < array[i-1])
            printf("Something went wrong");
    }

}

void print_array(int* array, int length){
    /* Output */
    printf("Sorted aray: ");
    for(int i=0; i<length; i++){
        printf("%d ", array[i]);
    }
}


int main(){
    int length, *array;
    get_input(&length, &array);
    // print_array(array, length);
    bubble_sort(array, length, is_greater);
    // check(array, 5);
    print_array(array, length);
    free(array);
    return 0;
}
