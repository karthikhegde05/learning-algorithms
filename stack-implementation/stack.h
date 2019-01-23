#ifndef STACK
#define STACK

struct Stack{
        int top;
        int capacity;//length of the array
        int* array;
};

struct Stack* createStack(unsigned capacity);
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, int x);
int pop(struct Stack* stack);
void printStack(struct Stack* stack);

#endif
