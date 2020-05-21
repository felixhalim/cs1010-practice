#include<stdio.h>

int contains(int x, int arrB[],int sizeB){
	int i;
	for(i=0;i<sizeB;i++){
		if(x==arrB[i])return 1;
	}
	return 0;
}

int isSubset(int arrA[], int sizeA, int arrB[], int sizeB){
	int i,ctr=0;
	for(i=0;i<sizeA;i++){
		if(contains(arrA[i],arrB,sizeB)){
			ctr++;
		}
	}
	if(ctr==sizeA)return 1;
	return 0;
}

int main(){
	int arrA[4], arrB[7];
	printf("1st array:\n");
	printf("Enter 4 values: ");
	int i;
	for(i=0;i<4;i++){
		scanf("%d",&arrA[i]);
	}
	printf("2nd array:\n");
	printf("Enter 7 values: ");
	for(i=0;i<7;i++){
		scanf("%d",&arrB[i]);
	}
	int case1 = isSubset(arrA,4,arrB,7);
	int case2 = isSubset(arrA,4,arrB,6);
	if(case1){
		printf("arrayA[0..3] is a subset of arrayB[0..6]");	
	}else{
		printf("arrayA[0..3] is not a subset of arrayB[0..6]");
	}
	printf("\n");
	if(case2){
		printf("arrayA[0..3] is a subset of arrayB[0..5]");
	}else{
		printf("arrayA[0..3] is not a subset of arrayB[0..5]");
	}
	printf("\n");
	return 0;
}
