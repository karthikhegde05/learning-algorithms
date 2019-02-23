#include<stdio.h>
#include<stdlib.h>

struct queueNode{
	int data;
	int* next;
};

struct Queue{
	struct queueNode *head, *tail;
};

struct Queue* createqueue();
int isEmpty(struct Queue* q);
void Enqueue(struct Queue* q, int x);//compiler throws a warning due to different pointer type of temp
int Dequeue(struct Queue* q);
void printList(struct Queue* q);


int main(){
	struct Queue* Que = createqueue();
	Enqueue(Que, 5);
	Enqueue(Que, 10);
	Enqueue(Que, 15);
	Enqueue(Que, 20);
	Enqueue(Que, 45);
	Enqueue(Que, 55);
	printList(Que);
	int x = Dequeue(Que);
	Dequeue(Que);
	printList(Que);
	printf("%d\n", x);
	return 0;
}

struct Queue* createqueue(){
	struct Queue* new = (struct Queue*)malloc(sizeof(struct Queue));
	new->head = NULL;
	new->tail = NULL;
	return new;
}

int isEmpty(struct Queue* q){
	return (q->head == NULL);
}

void Enqueue(struct Queue* q, int x){
	struct queueNode* temp = (struct queueNode*)malloc(sizeof(struct queueNode));
	temp->data = x;
	temp->next = NULL;
	if(isEmpty(q)){
		q->head = q->tail = temp;
		return;
	}
	q->tail->next = temp;
	q->tail = q->tail->next;
}

void printList(struct Queue* q){
	struct queueNode* temp;
	temp = q->head;
	if(isEmpty(q)){
		printf("is Empty\n");
		return;
	}
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	free(temp);
}

int Dequeue(struct Queue* q){
	int x;
	if(isEmpty(q)){
		printf("isEmpty\n");
		return;
	}
	struct queueNode* temp;
	x = q->head->data;
	temp = q->head;
	q->head = q->head->next;
	free(temp);
	return x;
}
