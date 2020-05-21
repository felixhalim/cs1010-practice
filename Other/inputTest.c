#include<stdio.h>

int main(){
	printf("Enter integers, terminate with ctrl-d\n");
	int ctr=0;
	int value;
	while(scanf("%d",&value) == 1){
		ctr++;
	}
	printf("Number of values entered = %d\n",ctr);
}
