#include<stdio.h>

int main(){
	int increase =1;
	int num;
	printf("Enter positive integer: ");
	scanf("%d",&num);
	int temp=num;
	do{
		printf("Enter positive integer: ");
		scanf("%d",&num);
		if(num>temp)temp=num;
		else increase=0;
	}while(increase==1&&num!=0);
	if(increase==1||num==0)printf("Data are in increasing order.\n");
	else printf("Data are not in increasing order.\n"); 
	
}
