#ifndef QUEUE
#define QUEUE


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
void printQueue(struct Queue*);

#endif
