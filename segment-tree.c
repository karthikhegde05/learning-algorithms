#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

//minimum query segment tree

/*----------working properly----------------*/

int* Build_ST(int* A, int n);
void Update(int* A, int n, int* ST, int i, int x);//i ->index, x ->required no.
int RMQ(int* A, int* ST, int l, int r, int i, int j, int k);

//Range Minimum Query
// l,r is the range of the root, (i,j) is the given range from which we have to output the index of the min element in the array

int main(){
	int arr[1000], n, i;
	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	int* ST = Build_ST(arr, n);
	int a = RMQ(arr, ST, 0, n-1, 2, 5, 0);
	int b = RMQ(arr, ST, 0, n-1, 3, 7, 0);
	Update(arr, n, ST, 2, 1);
	int c = RMQ(arr, ST, 0, n-1, 2, 5, 0);
	printf("%d, %d, %d\n", a, b, c);
	return 0;
}

int* Build_ST(int* A, int n){
	double m1, m2;
	int m, i;
	m1 = log((double)n)/log((double)2);
	m2 = floor(m1);
	if(m1 != m2){//n != 2^k
		m = (int)m1+1;
		m = (int)(pow(2.00, (double)(m)));	
		for(i=n; i<m; i++)
			A[i] = INT_MAX;
		n = m;
	}
	int* ST = (int*)malloc((2*n-1)*sizeof(int));
	for(i=0; i<n; i++)
		ST[i+n-1] = i;
	for(i=n-2; i>-1; i--){
		if(A[ST[2*i+1]] < A[ST[2*i+2]])
			ST[i] = ST[2*i+1];
		else 
			ST[i] = ST[2*i+2];
	}
	return ST;
}

void Update(int* A, int n, int* ST, int i, int x){
	A[i] = x;
	int l, j = n-1+i, k;
	while(j>0){
		k = (j-1)/2;
		if(A[ST[2*k+1]] < A[ST[2*k+2]])
			l = 2*k+1;
		else
			l = 2*k+2;
		ST[k] = ST[l];
		j = k;
	}
}


int RMQ(int* A, int* ST, int l, int r, int i, int j, int k){
	int mid = (l+r)/2, p1, p2;
	if(i<=l && r<=j)
		return ST[k];
	else if(r<=i || j<=l)
		return -1;
	else {
		p1 = RMQ(A, ST, l, mid, i, j, 2*k+1);
		p2 = RMQ(A, ST, mid+1, r, i, j, 2*k+2);
		if(p1==-1)
			return p2;
		else if(p2==-1)
			return p1;
		else if(A[p1]<A[p2])
			return p1;
		else 
			return p2;
	}
}






