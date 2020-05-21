#include<stdio.h>

int countJumps(int arr[], int size){
	int ctr=0,i;
	int currentPosition=0;
	int currentIdx =-1;
	int flag;
	do{
		flag=0;
		int possibleFurthest = currentPosition+50;
		for(i=currentIdx+1;i<size;i++){
			if(arr[i]<=possibleFurthest){
				currentIdx=i;
				flag=1;
			}
		}
		if(flag==0)return -1;
		ctr++;
		currentPosition=arr[currentIdx];
	}while(currentPosition<arr[size-1]);
	return ctr;
}

int main(){
	int n,i;
	printf("Enter number of rocks: ");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("%d\n",countJumps(arr,n));
}
