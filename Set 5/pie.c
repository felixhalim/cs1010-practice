#include<stdio.h>
#define MAX_CHERRIES 20

int maxCherries(int, int[]);
int sum(int, int, int[]);

int main(){
	int slices, cherries[MAX_CHERRIES], i;
	printf("Enter number of slices: ");
	scanf("%d",&slices);
	printf("Enter numbers of cherries: ");
	for(i=0;i<slices;i++){
		scanf("%d",&cherries[i]);
	}
	printf("The maximum number of cherries Alice can get is %d.\n",maxCherries(slices,cherries));
	return 0;
}

int sum(int s, int e, int c[]){
	int i;
	int sum=0;
	for(i=s;i<=e;i++)sum+=c[i];
	return sum;
}

int maxCherries(int num, int k[]){
	int n=num*2;
	int c[n];
	int i, start, end;
	int total=0;
	for(i=0;i<num;i++){
		total+=k[i];
	}
	for(i=0;i<n;i++){
		c[i]=k[i%num];
	}
	int max=-1;
	for(start=0;start<n;start++){
		for(end=start;end<n;end++){
			int alicePortion = sum(start,end,c);
			int bobPortion = total - alicePortion; 
			if(max<alicePortion && alicePortion<= bobPortion){
				max = alicePortion;
			}
		}
	}
	return max;
}
