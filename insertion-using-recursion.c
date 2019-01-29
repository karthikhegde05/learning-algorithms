#include<stdio.h>

void ISR(int* arr, int n);

int main(){
	int a[1000], n, i;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	ISR(a, n);
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void ISR(int* arr, int n){
	int key = arr[n-1];
	if(n > 0)
		ISR(arr, n-1);
	int i = n-2;
	while(i>-1 && arr[i] > key)
		arr[i+1] = arr[i--];
	arr[i+1] = key;
}
