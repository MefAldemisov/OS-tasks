/**
* Author: ALina Bogdanova BS18-04
* Date: 04.09.19
* Description: Quick sort
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


int partition(int* array, int low_index, int hight_index){
    /* Partition operation implementation */

    int pivot = array[low_index + (hight_index - low_index) / 2];
    while (1){
        while (array[low_index] < pivot){
            low_index++;
        }
        while (array[hight_index] > pivot){
            hight_index--;
        }
        if (low_index >= hight_index){
            return hight_index;
        }
        swap(&array[low_index], &array[hight_index]);

        low_index++;
        hight_index--;
        
    }

}

void quicksort(int* array, int low_index, int hight_index){
    /*  Sort itself */
    if (low_index < hight_index){
        int p = partition(array, low_index, hight_index);
        quicksort(array, low_index, p);
        quicksort(array, p+1, hight_index);
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
    quicksort(array, 0, length-1);
    // check(array, 5);
    print_array(array, length);
    free(array);
    return 0;
}
