/**
* Author: ALina Bogdanova BS18-04
* Date: 04.09.19
* Description: A program that creates a dobly-linked list
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
    struct node * previous;
    int value;
} Node;

/*-------------------- Globals ----------------------------------*/


Node* head; // pointer of the first element of the list
Node* tail; // pointer of the last element of the list

int size;   // amount of elements in the list

/*-------------------- Helpful functions ------------------------*/

Node* find_by_index(int is_after, int index){
    /* Index MUST be valid */
    
    int i;
    Node* current;
    if (is_after){
        i = 0;
        current = head;
        while (i < index){
            current = current->next;
            i ++;
        }
    }else{
        i = size+1;
        current = tail;
        while(i > index){
            current = current->previous;
            i --;
        }
    }
    return current;
}

int read_index_from_user(){
    /* Reads index from the user while it is not valid*/
    int index = -1;
    while (index < 0 || index > size){ // In case of stupid user
        printf("Enter the index of the element, before/after which a new element should be inserted or deleted\nIt MUST be less then %d (length of the list):\n", size);
        scanf("%d", &index);
    }
    return index;
}

int delete_by_valid_index(int is_after, int index){
    /*Removes the node after the given index*/

    Node* base = find_by_index(is_after, index);
    Node* to_remove = is_after ? base->next : base->previous;
    if (is_after){
        base->next = to_remove->next;
        base->next->previous = base;
    }else{
        base->previous = to_remove->previous;
        base->previous->next = base;
    }
    size--;
    free(to_remove);
}

/*--------------------- Required functions ----------------------*/

void print_list(){
    /** Outputs the value of each element
     * (While the 'next' node is not NP prints the value of current node)
    */

    Node* current = head;
    while(current->next != tail){
        current = current->next;
        printf("%d ", current->value);
    }

}


void insert_node(int is_after){
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
    Node* base = find_by_index(is_after, index);

    // 4. Insert new node
    if(is_after){
        new_node->next = base->next;
        new_node->previous = base;
        base->next = new_node;
        new_node->next->previous = new_node;
    }else{
        new_node->previous = base->previous;
        new_node->next = base;
        base->previous = new_node;
        new_node->previous->next = new_node;
    }
    // 5. Increase counter
    size ++;
}

void delete_node(int is_after){
    /* Delete element on the n-s place*/

    int index = size; // index is on the last place <=> nothing to delete

    if (is_after){
        while (index==size){ // Stupid user checking
            index = read_index_from_user();
        }
    }else{
        while (index==0){ // Stupid user checking
            index = read_index_from_user();
        }
    }
    delete_by_valid_index(is_after, index);
}

/*--------------------- Communication functions -----------------*/

void start(){
    /*Communication with the user*/

    int option; // command that should be runned
    int is_in_loop = 1;

    while(is_in_loop){

        printf("\nEnter the option:\n");
        printf("\t1 - to print list\n\t2 - to insert element after an index\n");
        printf("\t3 - to insert element before some index\n\t4 - to remove element after some index\n");
        printf("\t5 - to remove element before some index\n\t6 - to print the size\nelse - exit\n");

        scanf("%d", &option);

        switch(option){
            case 1:
                print_list();
                break;
            case 2:
                insert_node(1);
                break;
            case 3:
                insert_node(0);
                break;
            case 4:
                delete_node(1);
                break;
            case 5:
                delete_node(0);
                break;
            case 6:
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
        delete_by_valid_index(1, size - 2);
    }
    free(head); // remove last element
    free(tail); // remove the last element
}

/*--------------------- Main -------------------------------------*/


int main(){
    // create list
    head = (Node*) malloc(sizeof(Node)); // create the first element
    tail = (Node*) malloc(sizeof(Node)); // create the last element
    head->next = tail; 
    tail->previous = head;
    
    head->previous = (Node*)0; 
    tail->next = (Node*)0; 

    size = 0; 

    // execute commands
    start();
    // clear memory
    clear_memory();
    return 0;
}