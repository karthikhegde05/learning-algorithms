#include<stdio.h>
#include<stdlib.h>

/*--------working properly---------*/

//x->index, val ->value
void Add(int* BIT, int n, int x, int val);//n->size of A

void Update(int* A, int* BIT, int n, int x, int val);

int Sum(int* BIT, int x);//returns the sum of the first x elements in A

int RSQ(int* BIT, int i, int j);//returns the sum of the elements in the range (i, j)

/* indexing in this problem is slightly different where it starts from 1 instead of zero
/*To build the bst we just have to call Add for each element of the array in A*/



int main(){
	int arr[1000], BIT[1000], n, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++)
		scanf("%d", &arr[i]);
	for(i=1; i<=n; i++)
		Add(BIT, n, i, arr[i]);
	for(i=1; i<=n; i++)
		printf("%d ", BIT[i]);
	printf("\n");
	printf("%d %d\n", Sum(BIT, 3), RSQ(BIT, 3, 4));
	return 0;
}



void Add(int* BIT, int n, int x, int val){
	while(x<=n){
		BIT[x] += val;
		x += x&(-x);
	}
}

void Update(int* A, int* BIT, int n, int x, int val){
	Add(BIT, n, x, val-A[x]);
	A[x] = val;
}

int Sum(int* BIT, int x){
	int sum = 0;
	while(x>0){
		sum += BIT[x];
		x -= x&(-x);
	}
	return sum;
}

int RSQ(int* BIT, int i, int j){
	return Sum(BIT, j) - Sum(BIT, i-1);
}
