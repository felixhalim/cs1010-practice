/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex2
 * square_free.c
 * FELIX HALIM
 * T04
 * This program compute the number of square-free integers
 * in two ranges [lower1,upper1] and [lower2,upper2], compare
 * and report which range has more square-free integers.
 */

#include <stdio.h>

int isSF(int);
int computeSF(int, int);

int main(void) {
	int lower1, upper1, lower2, upper2;

	printf("Enter four positive integers: ");
	scanf("%d %d %d %d", &lower1, &upper1, &lower2, &upper2);

	int totalSF1 = computeSF(lower1,upper1);
	int totalSF2 = computeSF(lower2,upper2);

	if(totalSF1>totalSF2){
		printf("Range [%d, %d] has more square-free numbers: %d\n", lower1,upper1,totalSF1);
	}else if(totalSF1==totalSF2){
		printf("Both ranges have the same number of square-free numbers: %d\n",totalSF1);
	}else{	
		printf("Range [%d, %d] has more square-free numbers: %d\n", lower2,upper2,totalSF2);
	}

	return 0;
}


// This Function determines whether given number x
// is square-free integer or not, then return 1 if it
// is a square-free number, 0 if not
int isSF(int x){
	int i;
	for(i=2;i*i<=x;i++){
		if(x%(i*i)==0)return 0;
	}
	return 1;
}

// This Function computes the number of square-free integers
// in the range [lower,upper] and return int totalSF
// as the total square-free integers in given range
int computeSF(int lower, int upper){
	int i, totalSF=0;
	for(i = lower;i<=upper;i++){
		if(isSF(i)==1)totalSF++;
	}
	return totalSF;
}

