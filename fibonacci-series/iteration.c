#include<stdio.h>
#include<stdlib.h>

int fib(int n);

int main(){
	printf("%d %d\n", fib(5), fib(6));
	return 0;
}

int fib(int n){
	int* F = (int*)malloc((n+1)*sizeof(int));
	F[0] = 0;
	F[1] = 1;
	int i;
	for(i=2;i<=n;i++){
		F[i] = F[i-1] + F[i-2];
	}
	return F[n];
}	
