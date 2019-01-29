#include<stdio.h>

int Sum_of_two(int* arr, int size, int x);//misnomer the function is a solution to aproblem in the textbook->find the existence of two elements in a set of integers such that their sum is the given integer x
//here True = 0 and False = -1
int main(){
	printf("%d\n", Sum_of_two(a, n, 5));
	return 0;
}
int Sum_of_two(int* arr, int size, int x){
	int i, n = size;
	for(i=0; i<n; i++){
		int key = x - arr[i];
		if(Binary_Search(arr, i+1, n-1, key) == 0)
			return 0;
	}
	return -1;
}
