#include<stdio.h>
#include"queue-using-array.h"

int main(){
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
}

