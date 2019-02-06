#include<stdio.h>
#include<stdlib.h>

void Merge(int* A, int i, int j, int k);
void MergeSort(int* A, int i, int j);//working properly
void getarray(int* A, int* size);
void Printlist(int* A, int size);

int main(){
	int arr[1000], n;
	getarray(arr, &n);
	MergeSort(arr, 0, n-1);
	Printlist(arr, n);
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

void getarray(int* A, int* size){
	int i;
	scanf("%d", size);
	for(i=0; i<*size; i++)
		scanf("%d", &A[i]);
}

void Printlist(int* A, int size){
	int i;
	for(i=0; i<size; i++)
		printf("%d ", A[i]);
	printf("\n");
}
