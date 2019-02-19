#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void Swap(int* a, int* b);
int Partition(int* A, int i, int j);
int RFindRank(int* A, int i, int j, int r);
void Merge(int* A, int i, int j, int k);
void MergeSort(int* A, int i, int j);
int MB(int* A, int size, int T);//MinBuckets
int GT(int * A, int size, int k);

int main(){
	int n, T, arr[1000000], i, k;
	scanf("%d%d%d", &n, &T, &k);
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	printf("%d\n", MB(arr, n, T));
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

void Swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int* A, int i, int j){
	int p = A[i];
	int l = i+1, r = j;
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
	int k = r;
	Swap(&A[k], &A[i]);
	return k;
}

int RFindRank(int* A, int i, int j, int r){
	int p, k;
	if(i<=j){
		p = rand()%(j-i+1) + i;
		Swap(&A[i], &A[p]);
		k = Partition(A, i, j);
		if(r == j-k+1)
			return A[k];
		else if(r < j-k+1)
			return RFindRank(A, k+1, j, r);
		else 
			return RFindRank(A, i, k, r-j+k);
	}
	return 0;
}

int MB(int* A, int size, int T){
	MergeSort(A, 0, size-1);
	int l=0, r=0, count=0, key;
	while(l<size){
		key = A[l] + T;
		while(A[r] < key && r<size){
			r++;
		}
		count++;
		if(A[r] > key)
			l=r;
		else if(A[r] == key)
			l = r+1;
	}
	return count;
}


int GT(int* A, int size, int k){
	MergeSort(A, 0, size-1);
	int i, l = 0, sum, max = INT_MIN;
	A[0] = 0;
	for(i=1; i<size; i++)
		A[i] = A[i] - A[i-1];
	int* B = (int*)malloc(k-1*sizeof(int));
	for(i=1; i<k; i++)
		B[i] = RFindRank(A, 0, size-1, i);
	i=0;
	while(i<size && l<k-1){
		sum = 0;
		while(A[i] != B[l]){
			sum = sum+A[i];
			i++;
		}
		if(sum > max)
			max = sum;
		l++;
	}
	sum = 0;
	for(while i<)
	return max;
}



