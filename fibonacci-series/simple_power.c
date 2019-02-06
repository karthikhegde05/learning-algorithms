#include<stdio.h>

long int Power(int a, int n);

int main(){
	printf("%ld\n", Power(10, 10));//10**10 is out of bounds for integer datatype
	return 0;
}

long int Power(int a, int n){
	if(n == 0)
		return 1;
	else if(n == 1)
		return a;
	else if(n%2 == 0)
		return Power(a*a, n/2);
	else
		return a*Power(a*a, n/2);
}
