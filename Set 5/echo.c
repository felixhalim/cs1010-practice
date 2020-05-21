#include<stdio.h>
#define MAX_VALUE 100
void scan(int*, int*);
void echo(int, int*, int, int, int*);
void print(int*,int);

int main(){
	int size, arr[MAX_VALUE];
	int *p_size = &size;
	scan(p_size,arr);
	int k, p;
	printf("Enter number of echoes and decay percentage: ");
	scanf("%d %d", &k, &p);
	int modifiedArr[(k+1)*size];
	echo(size,arr,k,p,modifiedArr);
	print(modifiedArr,(k+1)*size);
		
	return 0;
}

void scan(int* p_size, int* arr){
	int size;
	printf("Enter size: ");
	scanf("%d",&size);
	*p_size = size;
	int i;
	printf("Enter values: ");
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	printf("\n");
}

void echo(int size, int* arr, int k, int p, int* modArr){
	int i, ctr=0;
	for(i=0;i<size;i++){
		modArr[i]=arr[i];
	}
	for(i = size ; i < (k+1)*size;i++){
		modArr[i]=(100-p)*modArr[i-size]/100;
	}
}

void print(int *arr, int size){
	int i;
	printf("The sound wave with echoes added: \n");
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	}printf("\n");
}
