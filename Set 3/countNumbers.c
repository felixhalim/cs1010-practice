#include<stdio.h>

int count_numbers(int x, int y, int divisor1, int divisor2){
	int i;
	int ctr=0;
	for(i = x;i<=y;i++){
		if(i%divisor1!=0&&i%divisor2!=0)ctr++;
	}
	return ctr;
}

int main(){
	int divisor1,divisor2;
	do{
		printf("Enter 2 divisors: ");
		scanf("%d %d",&divisor1,&divisor2);
	}while(divisor1==divisor2||divisor1<1||divisor2<1);

	int limit1,limit2;
	do{
		printf("Enter lower and upper limits: ");
		scanf("%d %d",&limit1,&limit2);
	}while(limit1>=limit2||limit1<1||limit2<1);

	printf("Answer = %d\n",count_numbers(limit1,limit2,divisor1,divisor2));
}
