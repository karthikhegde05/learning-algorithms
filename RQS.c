#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Swap(int*, int*);
int Partition(int* A, int i, int j);
void RQS(int* A, int i, int j);//randomised quiksort - working properly
void Printlist(int* A, int size);
void  getarray(int* A, int* size);

int main(){
	int arr[1000], i, n;
	getarray(arr, &n);
	RQS(arr, 0, n-1);
	Printlist(arr, n);
	return 0;
}

void Swap(int *a, int *b){
	int temp =  *a;
	*a = *b;
	*b = temp;
}

int Partition(int* A, int i, int j){
	int p = A[i];
	int l = i+1; 
	int r = j; 
	while(l<=r){
		while(l<=r && A[l] <= p)
			l++;
		while(l<=r && A[r] > p)
			r--;
		if(l<=r){
		Swap(&A[l], &A[r]);
		l++;
		r--;
		}
	}
	int k = l-1;
	Swap(&A[k], &A[i]);
	return k;
}

void RQS(int* A, int i, int j){
	if(i<j){
		int p = (rand()%(j-i+1))+i;
		Swap(&A[i], &A[p]);
		int k = Partition(A, i, j);
		RQS(A, i, k-1);
		RQS(A, k+1, j);	
	}	
}

void Printlist(int* A, int size){
	int i;
	for(i=0; i<size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

void getarray(int* A, int* size){
	//int* n = (int*)malloc(sizeof(int));
	int i;
	scanf("%d", size);
	for(i=0; i<*size; i++)
		scanf("%d", &A[i]);
	//return n;
}
