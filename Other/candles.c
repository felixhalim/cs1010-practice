/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex1
 * candles.c
 * A program to compute how many candles that one can burn in total
 * given n initial candles and k residual candle to make a new candle
 * FELIX HALIM
 * T04
 */
#include <stdio.h>

int count_candles(int, int);

int main(void) {
	int n,k;
	printf("Enter number of candles and \n");
	printf("number of residuals to make a new candle: ");
	scanf("%d %d", &n, &k);
	printf("Total candles burnt = %d\n", count_candles(n,k));

	return 0;
}

// This function takes integer n and k as input
// Value of k must be greater than 1
// The returned value (int sum) is the total number of candles burnt
int count_candles(int n, int k){
	int sum=0;
	while(n>=k){
		sum+=k;
		n-=(k-1);
	}
	sum+=n;
	return sum;
}
