#include<stdio.h>

int is_perfect(int x){
	int i,sum=0;
	for(i=1;i<x;i++){
		if(x%i==0)sum+=i;
	}
	if(sum==x)return 1;
	return 0;
}

int main(){
	int num;
	do{
		printf("Enter number: ");
		scanf("%d",&num);
		if(num<=0)return 0;
		printf("%d ",num);
		if(is_perfect(num)){
			printf("is a perfect number.");
		}else{
			printf("is not a perfect number.");
		}
		printf("\n");
	}while(num>0);
}
