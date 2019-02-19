#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* createCircularLink();

struct Node* createCircularLink(int){
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = NULL;
	node->next = 
}
