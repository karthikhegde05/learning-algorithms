#include<stdio.h>

int fib(int n);

int main(){
	printf("%d %d\n", fib(5), fib(6));
	int i=0;
	while(fib(i)<100){
		i++;
	}
	printf("%d %d\n %d %d\n", i, fib(i), i-1, fib(i-1));
	return 0;
}

int fib(int n){
	int a, b, c, i;
	a = 0;
	b = 1;
	c = a+b;
	if(n<2)
		return n;
	else if(n==2)
		return 1;
	for(i=3;i<=n;i++){
		a = b;
		b = c;
		c = a+b;
	}
	return c;
}
