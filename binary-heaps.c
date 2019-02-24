#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


/*working properly*/
void Swap(int* a, int* b);
void Bottom_Up_Heapify(int* A, int n, int i);
void Top_Down_Heapify(int* A, int n, int i);
void Add(int* A, int* n, int x);
int DeleteMin(int* A, int *n);
void Update(int* A, int n, int i, int p);//change ith index to p;
void BuildHeap(int* A, int n);
void HeapSort(int* A, int n);

int main(){
	int levelorder[1000000], n, i;
	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%d", &levelorder[i]);	
/*	Bottom_Up_Heapify(levelorder, n, n-1);//working
	for(i=0; i<n; i++)
		printf("%d ", levelorder[i]);
	printf("\n");
	Top_Down_Heapify(levelorder, n, 0);
	for(i=0; i<n; i++)
		printf("%d ", levelorder[i]);
	printf("\n");
	Add(levelorder, &n, 5);
	for(i=0; i<n; i++)
		printf("%d ", levelorder[i]);
	printf("\n");
	DeleteMin(levelorder, &n);
	for(i=0; i<n; i++)
		printf("%d ", levelorder[i]);
	printf("\n");*/
	HeapSort(levelorder, n);

	
	return 0;
}

void Swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Bottom_Up_Heapify(int* A, int n, int i){
	int p = (i-1)/2;
	while(p>=0){
		if(A[i] < A[p])
		{	Swap(&A[i], &A[p]);
			i = p;
			p = (i-1)/2;
		}
		else
			break;
	}
}

void Top_Down_Heapify(int* A, int n, int i){
	int l;
	while(2*i+2 < n){
		if(A[2*i+1] <= A[2*i+2])
			l = 2*i+1;
		else 
			l = 2*i+2;
		if(A[i] > A[l]){
			Swap(&A[i], &A[l]);
			i = l;
		}
		else 
			break;
	}
	if(2*i+1 == n-1 && A[i]>A[2*i+1])
		Swap(&A[i], &A[2*i+1]);
}

void Add(int* A, int* n, int x){
	A[(*n)++] = x;
	Bottom_Up_Heapify(A, (*n), (*n)-1);
}

int DeleteMin(int* A, int *n){
	int x = A[0];
	A[0] = A[--(*n)];
	Top_Down_Heapify(A, *n, 0);
	return x;
}

void Update(int* A, int n, int i, int p){
	if(A[i] < p){
		A[i] = p;
		Top_Down_Heapify(A, n, i);
	}
	else {
		A[i] = p;
		Bottom_Up_Heapify(A, n, i);
	}
}


void BuildHeap(int* A, int n){
	int i;
	for(i=(n/2)-1; i>-1; i--){
		Top_Down_Heapify(A, n, i);	
	}
}


void HeapSort(int* A, int n){
	BuildHeap(A, n);
	int i;
	while(n!=0)
		printf("%d ", DeleteMin(A, &n));
	printf("\n");
}
