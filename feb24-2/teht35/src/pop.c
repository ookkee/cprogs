#include<stackdemo.h>
#include<stdlib.h>
#include<stdio.h>

stack *pop(stack *sPtr) {

    int i = sPtr -> i;
    printf("| %d\t|\n", i);
    printf("|-------|\n");

    stack *prev;
    prev = sPtr -> prev;
    free(sPtr);

    return prev;
}
