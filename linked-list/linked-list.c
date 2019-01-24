#include<stdio.h>
#include<stdlib.h>
#include"linked-list.h"
/*
//linked-list node
struct Node{
	int data;
	struct Node *next;
};

struct Node* search_node(struct Node* head, int k);//working
struct Node* search_pos(struct Node* head, int pos);//working
void printList(struct Node* head);//working
void insert_at_beg(struct Node** head, int k);// working
void insert_at_pos(struct Node* head, int k, int pos);//indexing begins from zero =>working correctly
void insert_at_end(struct Node* head, int k);// working 
void delete_at_beg(struct Node** head);//working
void delete_at_pos(struct Node* head, int pos);//working
void delete_at_end(struct Node* head);//working
void print_reverse_list(struct Node* head);//working

int main(){
	struct Node* LL = NULL;
	insert_at_beg(&LL, 5);
	insert_at_beg(&LL, 10);
	insert_at_beg(&LL, 15);
	printList(LL);
	insert_at_pos(LL, 25, 2);
	printList(LL);
	insert_at_end(LL, 30);
	printList(LL);
	delete_at_beg(&LL);
	printList(LL);
	printf("%d %d\n", search_node(LL, 5)->data, search_pos(LL, 1)->data);
	delete_at_pos(LL, 4);
	printList(LL);
	delete_at_end(LL);
	printList(LL);
	print_reverse_list(LL);
	printf("\n");
	return 0;
}
*/
struct Node* search_node(struct Node* head, int k){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp = head;
	while(temp != NULL && temp->data != k)
		temp = temp->next;
	return temp;
}

struct Node* search_pos(struct Node* head, int pos){
	struct Node* pos_ptr = (struct Node*)malloc(sizeof(struct Node));
	pos_ptr = head;
	int count = 0;
	while(count != pos && pos_ptr != NULL){
		pos_ptr = pos_ptr->next;
		count++;
	}
	return pos_ptr;
}

void printList(struct Node* head){
	struct Node* temp;
	temp = head;
	while(temp!=NULL){
	printf("%d ", temp->data);
	temp = temp->next;
	}
	printf("\n");
}

void insert_at_beg(struct Node** head, int k){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = k;
	temp->next = *head;
	*head = temp;
}	
	
void insert_at_pos(struct Node* head, int k, int pos){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	struct Node* current = (struct Node*)malloc(sizeof(struct Node));
	struct Node* prev = (struct Node*)malloc(sizeof(struct Node));
	current = NULL;
	prev = NULL;
	int count = 0;
	if(pos==0){
		insert_at_beg(&head, k);		
	}
	else{
	current = head;
	temp->data = k;
	temp->next = NULL;
	while(count!=pos){
		prev = current;
		current = current->next;
		count++;
	}
	temp->next = current;
	prev->next = temp;
	}
	

}

void insert_at_end(struct Node* head, int k){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	struct Node* current = (struct Node*)malloc(sizeof(struct Node));
	struct Node* prev = (struct Node*)malloc(sizeof(struct Node));
	temp->data = k;
	temp->next = NULL;
	prev = NULL;
	current = head;
	while(current != NULL){
	prev = current;
	current = current->next;
	}
	prev->next = temp;
}


void delete_at_beg(struct Node** head){
	struct Node* temp = *head;
	*head = temp->next;
	temp->next = NULL;//not necessary to use free(temp) as temp has not been malloced(not stored in heap)	
}

void delete_at_pos(struct Node* head, int pos){
	struct Node* current;
	struct Node* prev = (struct Node*)malloc(sizeof(struct Node));
	prev = search_pos(head, pos-1);
	if(prev->next != NULL){
	current = prev->next;
	prev->next = current->next;
	current->next = NULL;
	free(current);
	}
	else{
	printf("position is out of bounds!\n");
	}
	
}


void delete_at_end(struct Node* head){
	struct Node* current;
	struct Node* prev = (struct Node*)malloc(sizeof(struct Node));
	current = head;
	prev = NULL;
	while(current->next != NULL){
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	free(current);
}


void print_reverse_list(struct Node* head){
	if(head == NULL)
		return;
	else{
		print_reverse_list(head->next);
		printf("%d ", head->data);
	}
}
