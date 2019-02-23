#include<stdio.h>
#include<stdlib.h>

void CountSort(int* A, int* B, int size, int k);

int main(){
	int n, k, A[100], B[100];
	scanf("%d%d", &n, &k);
	int i;
	for(i=0; i<n; i++)
		scanf("%d", &A[i]);
	CountSort(A, B, n, k);
	for(i=0; i<n; i++)
		printf("%d ", B[i]);
	printf("\n");
	return 0;
}


void CountSort(int* A, int* B, int size, int k){//all elements of array A are 0<=A[i]<k
	int* C = (int*)malloc(k*sizeof(int));
	int i, j;
	for(i=0; i<k; i++)
		C[i] = 0;
	for(j=0; j<size; j++)
		C[A[j]]++;
	for(i=1; i<k; i++)
		C[i] += C[i-1];
	for(j=size-1; j>=0; j--){
		B[C[A[j]]-1] = A[j];
		C[A[j]]--;	
	}
}
