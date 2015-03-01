#include<stackdemo.h>
#include<stdlib.h>

stack *push(stack *sPtr, int input) {

    stack *newPtr = (stack *)malloc(sizeof(stack));
    newPtr -> prev = sPtr;
    newPtr -> i = input;

    return newPtr;

}
