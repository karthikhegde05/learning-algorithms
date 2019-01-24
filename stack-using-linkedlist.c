#include<stdio.h>
#include<stdlib.h>

struct stackNode{
	int data;
	struct stackNode* next;
};

struct stackNode* createNode(int x);
void push(struct stackNode* top, int x);
int pop(struct stackNode* top);
void printStack(struct stackNode* top);
int isEmpty(struct stackNode* top);

int main(){
	struct stackNode* St = NULL;
	push(St, 25);
	push(St, 30);
	push(St, 45);
	printf("%d\n", pop(St));
	return 0;
}

/*struct stackNode* createNode(int x){
	struct stackNode* newnode = (struct stackNode*)malloc(sizeof(struct stackNode));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}*/

//push function
void push(struct stackNode* top, int x){
	struct stackNode* temp = (struct stackNode*)malloc(sizeof(struct stackNode));
	if(top == NULL){
	temp->data = x;
	temp->next = NULL;
	top = temp;
	}
	else{
	temp->data = x;
	temp->next = top;
	top = temp;
	}
		
}

//pop function
int pop(struct stackNode* top){
	struct stackNode* temp = (struct stackNode*)malloc(sizeof(struct stackNode));
	temp = top;
	top = temp->next;
	int x = temp->data;
	temp->next = NULL;
	free(temp);
	return x;
}

//print stack: should print reverse of linked list
void printStack(struct stackNode* top){
	struct stackNode* temp = (struct stackNode*)malloc(sizeof(struct stackNode));
	temp = top;
	if(temp==NULL)
		return;
	else{
		printStack(temp->next);
		printf("%d ", temp->data);
		return;
	}
}

//isempty
int isEmpty(struct stackNode* top){
	return top==NULL;
}
