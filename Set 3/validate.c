#include<stdio.h>

int main(){
	int age;
	int count=0;
	do{
		count++;
		printf("Enter age: ");
		scanf("%d",&age);
	}while(age>100||age<1);
	printf("Your age is %d.\n",age);
	printf("Number of attempts = %d\n",count);
	return 0;
}
