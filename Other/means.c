// means.c
// To compute the arithmetic mean and geometric mean of 3 positive integer.
#include <stdio.h>
#include <math.h>
void compute_AM_GM(int, int, int, float*, float*);
int main(void) {
	int num1, num2, num3;
	float am, gm;   // am = arithmetic mean; gm = geometric mean
	printf("Enter 3 positive integers: ");
	scanf("%d %d %d",&num1,&num2,&num3);
	compute_AM_GM(num1,num2,num3,&am,&gm);
	printf("Arithmetic mean = %.2f\n",am);
	printf("Geometric mean = %.2f\n",gm);
	return 0;
}

void compute_AM_GM(int num1, int num2, int num3, float* am, float*gm){
	*am = (num1+num2+num3)/3.0;
	*gm = pow((num1*num2*num3),(1.0/3));
	
}

