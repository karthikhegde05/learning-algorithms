#include<stdio.h>
#include<stdlib.h>
#include"queue-using-array.h"
/*
struct Queue{ //FIFO
	int head;//point to the front element
	int tail;//point to the rear element 
	int capacity;
	int size;
	int* array;
};

struct Queue* createQueue(int);
int isEmpty(struct Queue*);
int isFull(struct Queue*);
void enqueue(struct Queue*, int);
int dequeue(struct Queue*);
void printQueue(struct Queue*);*/

//main for checking validity of every function
/*int main(){
	struct Queue* Q = createQueue(10);
	printf("%d\n", isEmpty(Q));
	enqueue(Q, 5);
	enqueue(Q, 10);
	enqueue(Q, 15);
	enqueue(Q, 20);
	printQueue(Q);
	dequeue(Q);
	dequeue(Q);
	printQueue(Q);
	printf("%d\n", isFull(Q));
	enqueue(Q, 24);
	enqueue(Q, 34);
	enqueue(Q, 44);
	enqueue(Q, 54);
	enqueue(Q, 64);
	enqueue(Q, 74);
	printQueue(Q);
	printf("%d\n", isFull(Q));
	enqueue(Q, 94);
	printQueue(Q);
	printf("%d\n", isFull(Q));
	enqueue(Q, 84);
	printQueue(Q);
	printf("%d\n", isFull(Q));
	return 0;	
}*/

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
