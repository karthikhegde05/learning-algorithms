#include<stdio.h>
#include<stdlib.h>

struct Stack{
	int top;
	int capacity;
	int* array;
};

struct Queue{
	int capacity;
	struct Stack* stack1;
	struct Stack* stack2;
};

//done: this is properly working

struct Stack* createStack(int capacity);
struct Queue* createQueue(int capacity);
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, int x);
int pop(struct Stack* stack);
//int size(struct Queue* queue);
void Enqueue(struct Queue* queue, int x);
int Dequeue(struct Queue* queue);
void printQueue(struct Queue* queue);

int main(){
	struct Queue* queue = createQueue(10);
	Enqueue(queue, 5);
	Enqueue(queue, 6);
	Enqueue(queue, 7);
	Enqueue(queue, 10);
	printQueue(queue);
	Dequeue(queue);
	printQueue(queue);
	Dequeue(queue);
	printQueue(queue);
	Dequeue(queue);
	printQueue(queue);
	return 0;
}

struct Stack* createStack(int capacity){
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc((stack->capacity)*sizeof(int));
	return stack;
}

struct Queue* createQueue(int capacity){
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->stack1 = createStack(capacity);
	queue->stack2 = createStack(capacity);
	return queue;
}

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
		printf("overflow\n");
	else
		stack->array[++stack->top] = x;
}

//to pop 
int pop(struct Stack* stack){
	if(isEmpty(stack))
		printf("underflow\n");
	else
		return stack->array[(stack->top)--];
}

void Enqueue(struct Queue* queue, int x){//pushing into the queue
	push(queue->stack1, x);
}

/*int size(struct Queue* queue){
	if(isEmpty(queue->stack2))
		return queue->stack1->top;
	else
		return queue->stack2->top;
}*/

int Dequeue(struct Queue* queue){
	int i, x, y;
	while(queue->stack1->top != 0){
		x = pop(queue->stack1);
		push(queue->stack2, x);
	}
	x = pop(queue->stack1);

	while(queue->stack2->top != -1){
		y = pop(queue->stack2);
		push(queue->stack1, y);
		}
	return x;
}

void printQueue(struct Queue* queue){
	int i;
	for(i=0; i<=queue->stack1->top; i++){
		printf("%d ", queue->stack1->array[i]);
	}
	printf("\n");
}


