#include<stdio.h>

int sum_digits(int);

int main(){
	int num;
	printf("Enter a non-negative integer: ");
	scanf("%d", &num);
	printf("%d\n", sum_digits(num));
	
	return 0;
}

int sum_digits(int n){
	if(n<=0){
		return 0;
	}
	else{
		return n%10+sum_digits(n/10);
	}
}
