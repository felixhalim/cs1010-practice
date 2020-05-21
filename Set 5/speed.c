#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100000

void scan(int *ptr_size, int* val){
	int size;
	printf("Enter size: ");
	scanf("%d",&size);
	*ptr_size = size;
	
	int i;
	printf("Enter values: \n");
	for(i=0;i<size;i++){
		scanf("%d",&val[i]);
	}
}

void slowdown(int k, int* p, int* val){
	int size = *p;
	int copyVal[size];
	int i;
	k = abs(k);
	for(i=0;i<size;i++){
		copyVal[i]=val[i];
	}
	int j;
	for(i=0;i<size;i++){
		for(j=0;j<k;j++)
			val[k*i+j]=copyVal[i];
	}
	*p=size*k;
}

void speedup(int k, int *p, int* val){
	int size = *p;
	int copyVal[size];
	int i;
	for(i=0;i<size;i++){
		copyVal[i]=val[i];
	}
	int j,sum;
	for(i=0;i<size/k;i++){
		sum=0;
		for(j=k*i;j<k*i+k;j++){
			sum+=(copyVal[j]);
		}
		val[i]=sum/k;
	}
	*p=size/k;
}

void print(int size, int* val){
	int i;
	printf("The sound wave after speed change: \n");
	for(i=0;i<size;i++){
		printf("%d ",val[i]);
	}
}

int main(){
	
	int size;
	int *ptr_size=&size;
	int val[MAX_SIZE];

	scan(ptr_size,val);
	
	int k;
	printf("Enter speed change: ");
	scanf("%d",&k);
	if(k>0){
		speedup(k,ptr_size,val);
	}else{
		slowdown(k,ptr_size,val);
	}

	print(size,val);
	printf("\n");
	return 0;
}
