typedef struct Stack{
    int i;
    struct Stack *prev;
} stack;

stack *push();
stack *pop();
