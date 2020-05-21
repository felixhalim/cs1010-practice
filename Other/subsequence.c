/**
 * CS1010 AY2017/8 Semester 1 Lab4 Ex2
 * subsequence.c
 * This program reads in a list of integers and find the
 * k-interval subsequence with the largest sum.
 * FELIX HALIM
 * T04
 */
#include <stdio.h>
int scan_list(int []);
void sum_subsequence(int [], int, int []);
int main(void) {
	int list[10], size; // array and actual number of elements entered
	int answers[3];     // stores the required answers
	size = scan_list(list); 
	sum_subsequence(list, size, answers);
	printf("Max sum %d of %d-interval subsequence starting at position %d.\n",
			answers[0], answers[1], answers[2]);
	return 0;
}
// Read in elements for the array arr and returns the 
// number of elements read.
// Postcond: i > 0
int scan_list(int arr[]) {
	int num, i;
	printf("Enter number of elements: ");
	scanf("%d", &num);
	printf("Enter %d element%s: ", num, (num>1)?"s":"");
	for (i=0; i<num; i++) {
		scanf("%d", &arr[i]);
	}
	return num;
}
// Function to calculate the maximum sum of solution subsequence 
// Then assign the max sum, interval, start position to array ans[]
// ans[0] = maximum sum of solution subsequence
// ans[1] = interval k of the solution subsequence
// ans[2] = start position of the solution subsequence
void sum_subsequence(int arr[], int size, int ans[]) {
	int i, j, k, sum, max=-1;
	ans[1]=size+1;
	for(i=0;i<size;i++){
		for(j=0;j<i+1;j++){
			sum=0;
			for(k=j;k<size;k+=(i+1)){
				sum+=arr[k];
			}
			if(sum>max){
				max = sum;
				ans[0]=max;
				ans[1]=i+1;
				ans[2]=j;
			}	
		}
	}
}

