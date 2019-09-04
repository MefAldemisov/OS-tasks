/**
* Author: ALina Bogdanova BS18-04
* Date: 04.09.19
* Description: Pointer adresses and values output
*/

#include <stdio.h>

int main(){
    int* pc;
    int c;
    c = 22;
    printf("Address of c: %d\n", &c); // I'd change to %ls
    printf("Value of c: %d\n\n", c);
    pc = &c;
    printf("Address of pointer pc: %d\n", pc); // I'd change to %ls
    printf("Content of pointer pc: %d\n\n", *pc);
    c = 11;
    printf("Address of pointer pc: %d\n", pc); // I'd change to %ls
    printf("Content of pointer pc: %d\n\n", *pc);
    *pc = 2;
    printf("Address of c: %d\n", &c); // I'd change to %ls
    printf("Value of c: %d\n\n", c);
    return 0;
}