#include<stdio.h>
#include<stackdemo.h>

int main() {

    printf("\n");
    printf("Demo of stack implementation\n");
    printf("============================\n");
    printf("\nYou will be asked to input integers. They will be stored in a stack.\n");
    printf("They will then be presented and removed from the stack top to bottom.\n");

    printf("\n");
    printf("Type 'q' to stop giving input.\n");

    int num;
    stack *prev = NULL;

    while(1) {
        printf(">> ");
        if(scanf("%d", &num)==0)
            break;

        //printf("%d\n", num);
        prev = push(prev, num);
    }

    printf("\n\nYour stack:\n");

    while(prev != NULL) {
        prev = pop(prev);
    }
    //free(prev);

    return 0;
}
