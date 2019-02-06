#include<stdio.h>
#include<stdlib.h>

void Power(int A[][2], int N);
void Matrix_Multiply(int A1[][2], int A2[][2]);
//void Power(int A[][2], int N);
int Fib(int n);

int main(){
	printf("%d\n", Fib(6));
	return 0;
}

void Matrix_Multiply(int A1[][2], int A2[][2]){
	int a, b, c, d;
	a = A1[0][0]*A2[0][0] + A1[0][1]*A2[1][0];
	b = A1[0][0]*A2[0][1] + A1[0][1]*A2[1][1];
	c = A1[1][0]*A2[0][0] + A1[1][1]*A2[1][0];
	d = A1[1][0]*A2[0][1] + A1[1][1]*A2[1][1];
	A1[0][0] = a;
	A1[0][1] = b;
	A1[1][0] = c;
	A1[1][1] = d;
}

void Power(int A[2][2], int N){
	int Y[2][2] = {{1, 0}, 
			{0, 1}};
	while(N>0){
	if(N%2 != 0)
		Matrix_Multiply(Y, A);
	Matrix_Multiply(A, A);
	N = N/2;
	}
	A[0][0] = Y[0][0];
	A[0][1] = Y[0][1];
	A[1][0] = Y[1][0];
	A[1][1] = Y[1][1];
}

/*void Power(int A[][2], int N){
	int A2[2][2] = {{1, 1}, {1, 0}};
	if(N==1)
		return;
	else if(N%2==0){
		Matrix_Multiply(A, A);
		Power(A, N/2);
	}
	else{
		Power(A, N-1);
		Matrix_Multiply(A, A2);
	}
}*/

int Fib(int n){
	int A[2][2] = {{1, 1}, 
			{1, 0}};
	
	Power(A, n-1);
	return A[0][0];
}
