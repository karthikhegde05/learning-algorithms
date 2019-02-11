#include<stdio.h>
#include<stdlib.h>

struct Queue{ //FIFO
	int head;//point to the front element
	int tail;//point to the rear element 
	int capacity;
	int size;
	int* array;
};

struct Stack{
	int capacity;
	struct Queue* queue1;
	struct Queue* queue2;
};

struct Queue* createQueue(int);
int isEmpty(struct Queue*);
int isFull(struct Queue*);
void enqueue(struct Queue*, int);
int dequeue(struct Queue*);
void printQueue(struct Queue*);

struct Stack* createStack(int capacity);
void Push(struct Stack* stack, int x);
int Pop(struct Stack* stack);
void PrintStack(struct Stack* stack);

int main(){
	struct Stack* stack = createStack(10);
	Push(stack, 5);
	Push(stack, 6);
	Push(stack, 7);
	Push(stack, 10);
	PrintStack(stack);
	Pop(stack);
	PrintStack(stack);
	Pop(stack);
	PrintStack(stack);
	Pop(stack);
	PrintStack(stack);
	return 0;
}


//creates the queue
struct Queue* createQueue(int capacity){
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->head = 0;
	queue->tail = 0;
	queue->size = 0;
	queue->capacity = capacity;
	queue->array = (int*)malloc(queue->capacity*sizeof(int));
	return queue;
}


//isEmpty and isFull to check underflow and overflow
int isEmpty(struct Queue* queue){
	return queue->size == 0;
}

int isFull(struct Queue* queue){
	return queue->size == queue->capacity;
}

void enqueue(struct Queue* queue, int x){
	if(isFull(queue)==0){
	queue->array[queue->tail] = x;//tail is one element after last element
	queue->tail = (queue->tail+1)%(queue->capacity);
	queue->size++;
	}
	else
		printf("can't add queue is full!");
}

int dequeue(struct Queue* queue){
	int x;
	if(isEmpty(queue)==0){
	x = queue->array[queue->head];
	queue->head = (queue->head+1)%(queue->capacity);
	queue->size--;
	return x;
	}
	else{
		printf("queue is empty");
		return;
	}
}

void printQueue(struct Queue* queue){
	int i = queue->head;
	if(isFull(queue) == 0){//when full queue->head = queue->tail
	while(i!=queue->tail){
		printf("%d ", queue->array[i]);
		i = (i+1)%(queue->capacity);
	}
	printf("\n");
	}
	else{
		printf("%d ", queue->array[i++]);
		while(i!=queue->tail){
			printf("%d ", queue->array[i]);
			i = (i+1)%queue->capacity;
		}
		printf("\n");
	}
	
}

struct Stack* createStack(int capacity){
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->queue1 = createQueue(capacity);
	stack->queue2 = createQueue(capacity);	
	return stack;
}


void Push(struct Stack* stack, int x){
	enqueue(stack->queue1, x);
}

int Pop(struct Stack* stack){
	int x, y;
	while(stack->queue1->size != 1){
		x = dequeue(stack->queue1);
		enqueue(stack->queue2, x);
	}
	x = dequeue(stack->queue1);
	while(stack->queue2->size != 0){
		y = dequeue(stack->queue2);
		enqueue(stack->queue1, y);
	}
	return x;
}


void PrintStack(struct Stack* stack){
	printQueue(stack->queue1);
}
