#include<stdio.h>
#include<stdlib.h>

struct Queue{
	int head;
	int tail;
	int capacity;
	int* array;
};

struct Queue* createQueue(int);
int isEmpty(struct Queue*);
int isFull(struct Queue*);
void enqueue(struct Queue*, int);
int dequeue(struct Queue*);

//main for checking validity of every function
int main(){
	
}

//creates the queue
struct Queue* createQueue(int capacity){
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->head = 0;
	queue->tail = 0;
	queue->capacity = capacity;
	queue->array = (int*)malloc(queue->capacity*sizeof(int));
	return queue;
}


//isEmpty and isFull to check underflow and overflow
int isEmpty(struct Queue* queue){
	return queue->head == queue->tail;
}

int isFull(struct Queue* queue){
	return queue->tail >= queue->capacity;
}

void enqueue(struct Queue* queue, int x){
	if(isFull(queue)==0){
	queue->array[queue->tail] = x;
	queue->tail++;
	}
	else
		printf("can't add queue is full!");
}

int dequeue(struct Queue* queue){
	int x;
	if(isEmpty(queue)==0){
	x = queue->array[queue->head++];
	return x;
	}
	else{
		printf("queue is empty");
		return;
	}
}
