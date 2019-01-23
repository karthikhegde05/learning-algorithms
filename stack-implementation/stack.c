#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

/*struct Stack{
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

int main(){
	struct Stack* St = createStack(100);
	printf("%d\n", isEmpty(St));
	printStack(St);
	push(St, 10);
	printStack(St);
	push(St, 20);
	printStack(St);
	int d = pop(St);
	printStack(St);
	return 0;
}*/

//function to create a stack of given capacity
//stack as 0
struct Stack* createStack(unsigned capacity){
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc((stack->capacity)*sizeof(int));
	return stack;
}

//stack is full
int isFull(struct Stack* stack){
	return stack->top == stack->capacity-1;
}

//stack is empty when top is indexes -1
int isEmpty(struct Stack* stack){
	return stack->top == -1;
}

//to push an item into the stack
void push(struct Stack* stack, int x){
	if(isFull(stack))
		printf("overflow");
	else
		stack->array[++stack->top] = x;
}

//to pop 
int pop(struct Stack* stack){
	if(isEmpty(stack))
		printf("underflow");
	else
		return stack->array[(stack->top)--];
}


//to print the stack
void printStack(struct Stack* stack){
	int i;
	if(isEmpty(stack))
		printf("isempty!\n");
	else{
	
	for(i=0; i<=(stack->top); i++)
		printf("%d ", stack->array[i]);
	printf("\n");
	}
}
