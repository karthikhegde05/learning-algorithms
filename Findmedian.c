#include<stdio.h>

void Swap(int* a, int* b);
int Partition(int* A, int i, int j);
int RFindRank(int* A, int i, int j, int r);

int main(){
	int n, arr[1000000], i;
	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	printf("%d", RFindRank(arr, 0, n-1, n/2 + 1));
	return 0;
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
