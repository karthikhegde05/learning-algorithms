#include<stdio.h>
#include<stdlib.h>
#define MAX_LEN 100000

void merge(int* a, int p, int q, int r);

void merge_sort(int* a, int p, int r);	

int main(){
	int i, size;
	int a[MAX_LEN];
	scanf("%d", &size);
	for(i=0; i<size; i++)
		scanf("%d", &a[i]);
	merge_sort(a, 0, size-1);
	for(i=0; i<size; i++)
		printf("%d ", a[i]);
	printf("\n");
}


void merge(int* a, int p, int q, int r){
	int i, j, k;
	int n1 = q-p+1;
	int n2 = r-q;
	//creating l and r arrays
	int* left = (int*)malloc(n1*sizeof(int));
	int* right = (int*)malloc(n2*sizeof(int));
	for(i=0; i<n1; i++)
		left[i] = a[p+i-1];
	for(j=0; j<n2; j++)
		right[j] = a[q+j];
	
	i=1;
	j=1;
	k = p;
	while(i<n1 && j<n2){	
	
			if(left[i] <= right[j]){
			a[k] = left[i];
			i++;
			}
			else{
			a[k] = right[j];
			j++;
			}
	k++;
	}
		
	while(i==n1 && j<n2){
		a[k] = right[j];
		k++;
		j++;
		}
	while(j==n2 && i<n1){
		a[k] = left[i];
		k++;
		i++;
		}
				
	free(left);
	free(right);
}


void merge_sort(int* a, int p, int r){
	int q;
	if(p<r){
	q = (p + r)/2 ;
	merge_sort(a, p, q);
	merge_sort(a, q+1, r);
	merge(a, p, q, r);
	}
}	
