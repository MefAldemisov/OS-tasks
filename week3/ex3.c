/**
* Author: ALina Bogdanova BS18-04
* Date: 04.09.19
* Description: A program that creates a linked list*
* containing integers and uses the next functions:
*   – a function print_list() that will print out the value
* of each element
*   – a function insert_node() which will insert a new
* element after some existing element
*   – a function delete_node() which will delete a
* certain element
*/


#include <stdio.h>
#include <stdlib.h>

struct node;

typedef struct node{
    struct node * next;
    int value;
} Node;

/*-------------------- Globals ----------------------------------*/


Node* list; // pointer of the first element of the list
int size;   // amount of elements in the list

/*-------------------- Helpful functions ------------------------*/

Node* find_by_index(int index){
    /*Index MUST be valid*/
    int i = 0;
    Node* current = list;
    while (i < index){
        current = current->next;
        i ++;
    }
    return current;
}

int read_index_from_user(){
    /* Reads index from the user while it is not valid*/
    int index = -1;
    while (index < 0 || index > size){ // In case of stupid user
        printf("Enter the index of the element, after which a new element should be inserted or deleted\nIt MUST be less then %d (length of the list):\n", size);
        scanf("%d", &index);
    }
    return index;
}

int delete_by_valid_index(int index){
    /*Removes the node after the given index*/

    Node* previous = find_by_index(index);
    Node* to_remove = previous->next;
    previous->next = to_remove->next;
    size--;
    free(to_remove);
}

/*--------------------- Required functions ----------------------*/

void print_list(){
    /** Outputs the value of each element
     * (While the 'next' node is not NP prints the value of current node)
    */

    Node* current = list;
    while(current->next){
        current = current->next;
        printf("%d ", current->value);
    }

}


void insert_node(){
    /* Insert new element after n-s existing element*/

    // 1. Read new value
    int val;
    printf("Enter the int value to be stored in the new node:\n");
    scanf("%d", &val);

    // 2. Create a node
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->value = val;

    // 3. Search for the element to insert after + read the index of that element
    int index = read_index_from_user();
    Node* previous = find_by_index(index);

    // 4. Insert new node
    new_node->next = previous->next;
    previous->next = new_node;
    // 5. Increase counter
    size ++;
}

void delete_node(){
    /* Delete element on the n-s place*/

    int index = size; // index is on the last place <=> nothing to delete

    while (index==size){ // Stupid user checking
        index = read_index_from_user();
    }
    delete_by_valid_index(index);
}

/*--------------------- Communication functions -----------------*/

void start(){
    /*Communication with the user*/

    char option; // command that should be runned
    int is_in_loop = 1;

    while(is_in_loop){
        printf("\nEnter the option:\n\tp - to print list\n\ti - to insert element\n\td - to delete element\n\ts - get list's length\n\tsomething else - quit\n");
        do{
            scanf("%c", &option);
        }while(option <= 40); // soetimes additional '\n' are readen

        switch(option){
            case 'p':
                print_list();
                break;
            case 'i':
                insert_node();
                break;
            case 'd':
                delete_node();
                break;
            case 's':
                printf("%d", size);
                break;
            default:
                is_in_loop = 0; // exit
                break;
        }
    }
}

/*--------------------- Memory cleaning -------------------------*/

void clear_memory(){
    /*Frees all the list*/

    while(size > 1){ // removes the last element while the size is > 1
        delete_by_valid_index(size - 2);
    }
    free(list); // remove last element
}

/*--------------------- Main -------------------------------------*/


int main(){
    // create list
    list = (Node*) malloc(sizeof(Node)); // create the first element
    list->next = (Node*) 0; // null-pointer to stop the list
    size = 0; 

    // execute commands
    start();
    // clear memory
    clear_memory();
    return 0;
}