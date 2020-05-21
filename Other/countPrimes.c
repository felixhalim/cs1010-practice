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

int countPrime(int x){
	int i,ctr=0;
	for(i=1;i<=x;i++){
		if(is_prime(i))ctr++;
	}
	return ctr;
}

int main(){
	printf("Enter limit: ");
	int limit;
	scanf("%d",&limit);
	printf("Number of primes (1-%d): %d\n",limit,countPrime(limit));
	return 0;
}
