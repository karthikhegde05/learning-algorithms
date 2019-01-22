#include<stdio.h>
#include<stdlib.h>

struct Stack{
	int top;
	unsigned capacity;//length of the array
	int* array;
};

struct Stack* createStack(unsigned capacity);
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, int x);
int pop(struct Stack* stack);

int main(){
	struct Stack* S = createStack(1000);
	push(S, 25);
	push(S, 30);
	push(S, 45);
	printf("%d ", pop(S));
	printf("%d\n", pop(S));
	return 0;
}

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



