#include<stdio.h>

void BubbleSort(int* A, int size);
void Swap(int* a, int* b);
void getarray(int* A, int* size);
void Printlist(int* A, int size);


int main(){
	int arr[1000], n;
	getarray(arr, &n);
	BubbleSort(arr, n);
	Printlist(arr, n);
	return 0;
}


void BubbleSort(int* A, int size){
	int i, j;
	for(i=0; i<size; i++){
		for(j=i+1; j<size; j++){
			if(A[i]>A[j])
				Swap(&A[i], &A[j]);
			}
		}
	}

void Swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void getarray(int* A, int* size){
	scanf("%d", size);
	int i;
	for(i=0; i<*size; i++)
		scanf("%d", &A[i]);
}

void Printlist(int* A, int size){
	int i;
	for(i=0; i<size; i++)
		printf("%d ", A[i]);
	printf("\n");
}
