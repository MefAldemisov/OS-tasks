/**
* Author: Alina Bogdanova BS18-04
* Date: 18.09.19
* Description: smallest common denumibator search
* */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int data_length;
int* data;

int prime_table_length;
int** prime_table; // array of prime numbers till the biggest with the largest popularity of index

/**==========================Testing functions===============================**/

void print_array(){
    /**Prints the 'data' array*/
    for(int i=0; i < data_length; i++){
        printf("%d ", data[i]);
    }
}

/**==========================Input reading====================================**/

int count_lines(char* file_name){
    /* Returns amount of lines in the file 
    *  (current directory)*/
    FILE* file = fopen(file_name, "r");
    int n_lines = 0;
    char c;
    while((c=fgetc(file)) != EOF){
        fprintf(stderr, "%c", c);
        if(c=='\n'){
            n_lines++;
        }else if( (c < '0' || c >'9') && c <= 126){
            fclose(file);
            fprintf(stderr, "Input is invalid (%c, %d)\n", c, c);
            return -1;
        }
    }
    fclose(file);
    return n_lines;
}

void create_data_array(char* file_name){
    /**
    * Creates an fills the array
    * WARNING: 'data_length' should be defined
    */
    data = (int*) calloc(data_length, sizeof(int)); // creates array
    FILE* file = fopen(file_name, "r");
    int i = 0;
    // fill the print_array
    while(i < data_length)
        fscanf(file, "%d", &data[i++]);

    fclose(file);
}

int get_input(char* file_name){
    /**/
    // count amount of lines in the file
    int lines = count_lines(file_name);
    if(lines < 0){
        return -1;
    }
    data_length = lines;
    // fill the array
    create_data_array(file_name);
    return 0; // if everything is ok
}

/**====================Agorithm preparation==================**/

int find_maximum(){
    /**Serchs for max value in the data array**/
    int max_val = data[0];
    for (int i=1; i<data_length; i++){
        if(max_val < data[i])
            max_val = data[i];
    }
    return max_val;
}


int is_prime(int n){
    /* Returns 1 id the given number is prime, 
    *  0 - otherwise*/
    for(int i=2; i <= sqrt(n); i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}

int get_next_prime(int n){
    /* Returns the next prime number before n */
    printf("NOW %d\n", n);
    int current = n - 1;
    while(! is_prime(current)){
        current--;
    }
    return current;
}

int cout_primpes_smaller_then(int n){
    /* Retuns amount of prime numbers less then n*/
    int current = n;
    int count = 0;
    while(current != 1){
        current = get_next_prime(current);
        count ++;
    }
    return count;
}

void create_table(){    
    /* Creates 2D array with the first row - prime numbers
    second rov - their amount in the least common denumenator*/
    int max_value = find_maximum();
    printf("Max value: %d\n", max_value);
    prime_table_length = cout_primpes_smaller_then(max_value);
    printf("Table length: %d\n", prime_table_length);
    prime_table = (int**) calloc(prime_table_length, sizeof(int *));
    current = max_value;
    for(int i=prime_table_length-1; i >=0; i--){
        prime_table[i] = (int*) calloc(p)
        {current=get_next_prime(current), 0};         
    }    
}

/**=========================Threads Part=========================**/

int last_index = 0;

int get_next_index(){
    return last_index++;
}

void thread_runner(){
    while(1){
        // get the next index of a cell
        int index;
        if((index=get_next_index()) >= data_length){
            pthread_exit(pthread_self());
        }

        // find amount of division on each number
        // try to update the table
        
    }
}



int main (int argc, char* argv[]){

    if (argc != 3){
        printf("Incorrect input: two arguments required\n");
        return 0;
    }

    char* file_name = argv[1];
    int n_threads = atoi(argv[2]);

    int valid_input = get_input(file_name);
    if(valid_input < 0)
        return 0;

    // print_array();



    create_table();

    pthread_t threads[n_threads];
    for (int i=0; i<n_threads; i++){
        pthread_create(&threads[0], NULL, thread_runner, NULL);
    
    }

    // create array of threads
    // function of thread:
    //  1) get the next number
    //  2) try to divide on each cell of the array -> udate the values:
    //      Update: LOCKED table, if the value inside the table is less, then new-> update
    // multiply the content of the table
    return 0;

} 