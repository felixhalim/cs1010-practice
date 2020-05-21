#include<stdio.h>

int get_magic(int x){
	int sum=0;
	while(x>0){
		sum+=x%10;
		x/=100;
	}
	return sum%10;
}

int main(){
	int value1, value2;
	printf("Enter 1st value: ");
	scanf("%d",&value1);
	printf("Magic number = %d\n",get_magic(value1));
	printf("Enter 2nd value: ");
	scanf("%d",&value2);
	printf("Magic number = %d\n",get_magic(value2));
	return 0;
}
