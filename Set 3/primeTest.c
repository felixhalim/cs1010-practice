#include<stdio.h>

int is_prime(int x){
	if(x==1)return 0;
	if(x==2)return 1;
	int i=2;
	for(i=2;i<x;i++){
		if(x%i==0)return 0;
	}
	return 1;
}

int main(){
	int n;
	printf("Enter a positive integer: ");
	scanf("%d",&n);
	(is_prime(n))?(printf("%d is a prime.",n)):(printf("%d is not a prime.",n));
	printf("\n");
}

