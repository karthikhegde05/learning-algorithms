#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void Merge(int* A, int i, int j, int k);
void MergeSort(int* A, int i, int j);
int GT(int* A, int n, int k);//GiveT

int main(){
	int n, k, arr[1000000], i;
	scanf("%d%d", &n, &k);
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	printf("%d", GT(arr, n, k));
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


int GT(int* A, int n, int k){//n => size
	MergeSort(A, 0, n-1);
	int l = n-1, r = n-(n/k), max = INT_MIN;
	while(l>0){
		if(A[l] - A[r] > max)
			max = A[l] - A[r];
		l = r-1;
		r = r-(n/k);	
	}
	return max;
}




