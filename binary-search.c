#include<stdio.h>

int Binary_Search(int*, int, int, int);//returns 0 if True and -1 if False

int main(){
	int a[1000], i, n;
	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	printf("%d\n", Binary_Search(a, 0, n-1, 5));
	printf("%d\n", Sum_of_two(a, n, 5));
	return 0;
}

int Binary_Search(int* arr, int i, int j, int x){
	if(j>=i){
		int m = (i+j)/2;
		if(arr[m] == x)
			return 0;
		else if(arr[m]>x)
			Binary_Search(arr, i, m-1, x);
		else
			Binary_Search(arr, m+1, j, x);
	}
	else
		return -1;
}
