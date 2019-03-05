#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void Swap(int* a, int* b);

/*min heap functions*/ //using k, j as indices k->j exluding j and including k
void Min_Bottom_Up_Heapify(int* A, int k, int j, int i);
void Min_Top_Down_Heapify(int* A, int k, int j, int i);
void Add_for_min(int* A, int* k, int* j, int x);
int DeleteMin_for_min(int* A, int* k, int* j);//modified
void Update_for_min(int* A, int k, int j, int i, int p);//change ith index to p;
void BuildHeap_for_min(int* A, int k, int j);
void HeapSort(int* A, int k, int j);

/*max heap*/
void Max_Bottom_Up_Heapify(int* A, int k, int j, int i);
void Max_Top_Down_Heapify(int* A, int k, int j, int i);
void Add_for_max(int* A, int* k, int* j, int x);
int DeleteMax_for_max(int* A, int *k, int* j);
void Update_for_max(int* A, int k, int j, int i, int p);//change ith index to p;
void BuildHeap_for_max(int* A, int k, int j);

/*the required datastructure*/
void Add_dds(int* A, int** k2, int** j2, int x);//for max_heap size is n2 and n1 for min_heap;
int DeleteMedian(int* A, int** k1, int** j1, int** k2, int** j2);

int main(){
	int arr[1000000], n, i, *k1, *k2, *j1, *j2;
	scanf("%d", &n);
	int a = 0, b=n/2;
	k1 = &a, k2 = &b, j1 = &b, j2=&n;
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	HeapSort(arr, *k1, *j2);
	BuildHeap_for_max(arr, *k1, *j1);
	BuildHeap_for_min(arr, *k2, *j2);
	//Add_dds(arr, &k2, &j2, 10);
	for(i=(*k1); i<(*j2); i++)
		printf("%d ", arr[i]);
	printf("\n");
	int x = DeleteMedian(arr, &k1, &j1, &k2, &j2);
	printf("%d\n", x);
	return 0;
}



void Swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Min_Bottom_Up_Heapify(int* A, int k, int j, int i){
	int p = (i-1)/2;
	while(p>=k){
		if(A[i] < A[p])
		{	Swap(&A[i], &A[p]);
			i = p;
			p = (i-1)/2;
		}
		else
			break;
	}
}

void Min_Top_Down_Heapify(int* A, int k, int j, int i){
	int l;
	while(2*i+2 < j){
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
	if(2*i+1 == j-1 && A[i]>A[2*i+1])
		Swap(&A[i], &A[2*i+1]);
}

void Add_for_min(int* A, int* k, int* j, int x){
	A[(*j)++] = x;
	Min_Bottom_Up_Heapify(A, *k, *j, (*j)-1);
}

int DeleteMin_for_min(int* A, int* k, int* j){
	int x = A[(*k)++];
	Min_Top_Down_Heapify(A, *k, *j, *k);
	return x;
}

void Update_for_min(int* A, int k, int j, int i, int p){
	if(A[i] < p){
		A[i] = p;
		Min_Top_Down_Heapify(A, k, j, i);
	}
	else {
		A[i] = p;
		Min_Bottom_Up_Heapify(A, k, j, i);
	}
}


void BuildHeap_for_min(int* A, int k, int j){
	int i;
	for(i=(j/2)-1; i>k-1; i--){
		Min_Top_Down_Heapify(A, k, j, i);	
	}
}


void HeapSort(int* A, int k, int j){
	int i, x;
	BuildHeap_for_min(A, k, j);
	for(i=k; i<j; i++){
		Swap(&A[k], &A[j-1-i]);
		Min_Top_Down_Heapify(A, k, j-i-1, k);
	}
	int l=k, r=j-1;
	while(l<r){
		Swap(&A[l], &A[r]);
		l++;
		r--;
	}
}

void Max_Bottom_Up_Heapify(int* A, int k, int j, int i){
	int p = (i-1)/2;
	while(p>=k){
		if(A[i] > A[p])
		{	Swap(&A[i], &A[p]);
			i = p;
			p = (i-1)/2;
		}
		else
			break;
	}
}

void Max_Top_Down_Heapify(int* A, int k, int j, int i){
	int l;
	while(2*i+2 < j){
		if(A[2*i+1] >= A[2*i+2])
			l = 2*i+1;
		else 
			l = 2*i+2;
		if(A[i] < A[l]){
			Swap(&A[i], &A[l]);
			i = l;
		}
		else 
			break;
	}
	if(2*i+1 == j-1 && A[i]<A[2*i+1])
		Swap(&A[i], &A[2*i+1]);
}


void Add_for_max(int* A, int* k, int* j, int x){
	A[(*j)++] = x;
	Min_Top_Down_Heapify(A, (*k), (*j), *k);
}

int DeleteMax_for_max(int* A, int *k, int* j){
	int x = A[(*k)];
	A[*k] = A[--(*j)];
	Min_Bottom_Up_Heapify(A, *k, *j, (*j)-1);
	return x;
}

void Update_for_max(int* A, int k, int j, int i, int p){
	if(A[i] > p){
		A[i] = p;
		Max_Top_Down_Heapify(A, k, j, i);
	}
	else {
		A[i] = p;
		Max_Bottom_Up_Heapify(A, k, j, i);
	}
}

void BuildHeap_for_max(int* A, int k, int j){
	int i;
	for(i=(j/2)-1; i>k-1; i--){
		Max_Top_Down_Heapify(A, k, j, i);	
	}
}

/*---------------------------------------------------------*/

void Add_dds(int* A, int** k2, int** j2, int x){
	Add_for_min(A, *k2, *j2, x);
}

int DeleteMedian(int* A, int** k1, int** j1, int** k2, int** j2){
	int x;
	while((**j1)-(**k1)+1!= ((**j2)-(**k2)+1)+1 || (**j1)-(**k1)+1 != (**j2)-(**k2)+1){
		x = DeleteMin_for_min(A, *k2, *j2);
		Add_for_max(A, *k1, *j1, x);
	}
	return DeleteMax_for_max(A, *k1, *j1);
}
