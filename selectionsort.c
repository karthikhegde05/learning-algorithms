#include<stdio.h>
#include<limits.h>

void Swap(int* a, int* b);
void getarray(int* A, int* size);
void Printlist(int* A, int size);
void SelectionSort(int* A, int size);

int main(){
	int arr[1000], n;
	getarray(arr, &n);
	SelectionSort(arr, n);
	Printlist(arr, n);
	return 0;
}

void Swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
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

void SelectionSort(int* A, int size){
	int i, j;
	for(i=0; i<size-1; i++){
		int min = i;//this function doesnot work when min = A[i]
		for(j=i+1; j<size; j++){
			if(A[j]<A[min])
				min = j;
		}
		Swap(&A[i], &A[j]);
	}
}
