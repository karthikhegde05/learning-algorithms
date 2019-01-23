#include<stdio.h>
#include<stdlib.h>

struct stackNode{
	int data;
	struct stackNode* next;
};

struct stackNode* newnode(int newdata);
void push(struct stackNode* top, int x);
int pop(struct stackNode* top);

int main(){
	struct stackNode* S = NULL;
	push(S, 25);
	push(S, 30);
	push(S, 45);
	printf("%d\n", pop(S));
	return 0;
}

//creates a new node after which can be pushed
struct stackNode* newnode(int newdata){
	struct stackNode* newnode = (struct stackNode*)malloc(sizeof(struct stackNode));
	
	newnode->data = newdata;
	newnode->next = NULL;
	return newnode;
}

//push function
void push(struct stackNode* top, int x){
	struct stackNode* temp = newnode(x);
	temp->next = top;
	top = temp;
	printf("pushed %d\n", x);
}

//pop function
int pop(struct stackNode* top){
	struct stackNode* temp = (struct stackNode*)malloc(sizeof(struct stackNode));
	temp = top;
	top = top->next;
	int x = temp->data;
	free(temp);
	printf("popped %d\n", x);
	return x;
}

