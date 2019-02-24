#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


//the entire code is working properly except for some warnings while compilation but the output is correct;
struct node{//Binary Search Tree
	int key;
	struct node* rc;//right-child
	struct node* lc;//left-child
	struct node* p; //parent
	int h;//height
	int l;//level
};


struct queueNode{
	struct node* data;
	int* next;
};


struct Queue{
	struct queueNode *head, *tail;
};


struct Queue* createqueue();
int isEmpty(struct Queue* q);
void Enqueue(struct Queue* q, struct node* x);//compiler throws a warning due to different pointer type of temp
struct node* Dequeue(struct Queue* q);
void printList(struct Queue* q);


struct node* createNode();
void Merge(int* A, int i, int j, int k);
void MergeSort(int* A, int i, int j);
struct node* BuildBST(int* A, int i, int j, struct node* head);
void Visit(struct node* root);
void PreOrder(struct node* head);
void PostOrder(struct node* head);
void InOrder(struct node* head);
void Level(struct node* head);
void Height(struct node* head);
void LevelOrder(struct node* head, struct Queue* queue);



int main(){
	int arr[1000], n, i;
	scanf("%d", &n);
	for(i=0; i<n; i++)
		arr[i] = rand()%INT_MAX;
	MergeSort(arr, 0, n-1);
	struct node* head = BuildBST(arr, 0, n-1, NULL);
	PreOrder(head);
	printf("\n");
	PostOrder(head);
	printf("\n");
	InOrder(head);
	printf("\n");
	Level(head);
	printf("\n");
	Height(head);
	printf("\n");
	struct Queue* queue = createqueue();
	LevelOrder(head, queue);
	printf("\n");
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

void Enqueue(struct Queue* q, struct node* x){
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

struct node* Dequeue(struct Queue* q){
	struct node* x = (struct node*)malloc(sizeof(struct node));
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


struct node* createNode(){
	struct node* Node = (struct node*)malloc(sizeof(struct node));
	Node->key = 0;
	Node->rc = NULL;
	Node->lc = NULL;
	Node->p = NULL;
	Node->h = 0;
	Node->l = 0;
}


void Merge(int* A, int i, int j, int k){
	int* B = (int*)malloc((j-i+2)*sizeof(int));
	int l = i;
	int r = k+1;
	int p = 0;
	while(l<=k && r<=j){
		if(A[l]<=A[r])
			B[p++] = A[l++];
		else
			B[p++] = A[r++];
	} 
	while(l<=k)
		B[p++] = A[l++];
	while(r<=j)
		B[p++] = A[r++];
	p = 0;
	l = i;
	while(l<=j)
		A[l++] = B[p++];	
	free(B);
}

void MergeSort(int* A, int i, int j){
	int m;
	if(i<j){
		m = (i+j)/2;
		MergeSort(A, i, m);
		MergeSort(A, m+1, j);
		Merge(A, i, j, m);	
	}
}


struct node* BuildBST(int* A, int i, int j, struct node* head){
	int k;
	struct node* x;
	if(i<j){
		k = (i+j)/2;
		x = createNode();
		x->key = A[k];
		x->p = head;
		if(i<=k-1)
			x->lc = BuildBST(A, i, k-1, x);//else x->lc = NULL
		else 
			x->lc =NULL;
		if(k+1 <= j)
			x->rc = BuildBST(A, k+1, j, x);//else x->rc = NULL
		else 
			x->rc = NULL;
	}
	else if(i==j){
		x = createNode();
		x->key = A[i];
		x->lc = x->rc = NULL;
		x->p = head;
	}
	return x;
}



void Visit(struct node* root){
	printf("%d, ", root->key);
}

void PreOrder(struct node* head){
	if(head != NULL){
		Visit(head);
		PreOrder(head->lc);
		PreOrder(head->rc);
	}
}

void PostOrder(struct node* head){
	if(head != NULL){
		PostOrder(head->lc);
		PostOrder(head->rc);
		Visit(head);
	}
}

void InOrder(struct node* head){
	if(head != NULL){
		InOrder(head->lc);
		Visit(head);
		InOrder(head->rc);
	}
}

void Level(struct node* head){
	if(head != NULL){
	if(head->p != NULL){
		head->l = head->p->l + 1;
		printf("%d ", head->l);
		Level(head->lc);
		Level(head->rc);
	}
	else{
		head->l = 0;
		printf("%d ", head->l);
		Level(head->lc);
		Level(head->rc);
	}
	}
}

void Height(struct node* head){
	if(head != NULL){
		Height(head->lc);
		Height(head->rc);
		if(head->p != NULL){
		if(head->p->h <= head->h)
			head->p->h = head->h + 1;
		}
		printf("%d ", head->h);
	}
}

void LevelOrder(struct node* head, struct Queue* queue){
	struct node* temp = head;
	while(temp != NULL){
		Visit(temp);
		if(temp->lc != NULL)
			Enqueue(queue, temp->lc);
		if(temp->rc != NULL)
			Enqueue(queue, temp->rc);
		if(isEmpty(queue))
			break;
		temp = Dequeue(queue);
	}	
}
