#include<stdio.h>
#include<stdlib.h>

//linked-list node
struct Node{
	int key;
	struct Node *next;
};


struct Node* list_search(struct Node *head, int k);
void printlist(struct Node* head);

int main(int argv, char* argc[]){
	
	for()
}

//linked-list list-search
struct Node* list_search(struct Node *head, int k){
	struct Node *x = (struct Node*)malloc(sizeof(struct Node));
	*x = *head;
	while (x != NULL && (x->key) != k)
		x = x->next;
	return x;
}

//printlist
void printlist(struct Node* n){
	while(n->next != NULL){
		printf("%d, ", n->key);
		n = n->next;
	}
	printf("%d\n", n->key);
}
