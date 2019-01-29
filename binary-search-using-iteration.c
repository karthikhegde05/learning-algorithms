#include<stdio.h>

int BS(int*, int, int, int);//0 when True, -1 when False(uses iteration and not reccursion)

int main(){
	int a[1000], i, n;
	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	printf("%d\n", BS(a, 0, n-1, 5));
	return 0;
}

int BS(int* arr, int i, int j, int x){
	while(i<=j){
		int m = (i+j)/2;
		if(arr[m] == x)
			return 0;
		else if(arr[m] > x)
			j = m-1;
		else 
			i = m+1;
	}
	return -1;
}
