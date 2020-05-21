#include<stdio.h>

int isAscending(int a, int b, int c){
	a/=100;a%=10;
	b/=100;b%=10;
	c/=100;c%=10;
	if(a<b && b<c)return 1;
	return 0;
}

int main(){
	int a,b,c;
	printf("Enter 3 positive integers: ");
	scanf("%d %d %d",&a,&b,&c);
	printf("The integers are %d, %d and %d",a,b,c);
	if(isAscending(a,b,c)==1){
		printf("\nYes\n");
	}else{
		printf("\nNo\n");
	}
	return 0;
}
