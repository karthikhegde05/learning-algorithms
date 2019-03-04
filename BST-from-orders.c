#include<stdio.h>
#include<stdlib.h>
//This rebuilds the tree given inorder and preorder arrays.
//works properly

struct node{//Binary Search Tree
	int key;
	struct node* rc;//right-child
	struct node* lc;//left-child
	struct node* p; //parent
	int h;//height
	int l;//level
};

void Swap(int* a, int* b);
struct node* createNode();
int Binary_Search(int*, int , int, int);
void Merge(int* A, int i, int j, int k);
void MergeSort(int* A, int i, int j);
struct node* BuildBST(int* A, int i, int j, struct node* head);
void Visit(struct node* root);
void PreOrder(struct node* head);
void PostOrder(struct node* head);
void InOrder(struct node* head);
void Level(struct node* head);
void Height(struct node* head);
struct node* Tree_from_order(int* P, int* I, int i, int j, struct node* head);


int main(){
	int pre[1000], in[1000], n, i;
	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%d", &pre[i]);
	for(i=0; i<n; i++)
		scanf("%d", &in[i]);
	struct node* root = Tree_from_order(pre, in, 0, n-1, NULL);
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");		
	return 0;
}

void Swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
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


int Binary_Search(int* arr, int i, int j, int x){
	if(j>=i){
		int m = (i+j)/2;
		if(arr[m] == x)
			return m;
		else if(arr[m]>x)
			Binary_Search(arr, i, m-1, x);
		else
			Binary_Search(arr, m+1, j, x);
	}
	else
		return 0;
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

struct node* Tree_from_order(int* P, int* I, int i, int j, struct node* head){
	struct node* x;
	int k, c;
	if(i<j){	
		k = Binary_Search(I, i, j, P[i]);
		x = createNode();
		x->key = P[i];
		x->p = head;
		for(c=i; c<k; c++)
			Swap(&P[c], &P[c+1]);
		x->lc = Tree_from_order(P, I, i, k-1, x);
		if(k != j)
			x->rc = Tree_from_order(P, I, k+1, j, x);
		else 
			x->rc = NULL;
	}
	else if(i==j){
		x = createNode();
		x->key = P[i];
		x->p = head;
		x->lc = x->rc = NULL;
	}
	return x;
}



