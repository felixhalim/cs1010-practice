/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex3
 * bisection.c
 * FELIX HALIM
 * T04
 * This program calculates the root of a continuous function
 * using Bisection method which takes 4 integers as degree of
 * polynomial and 2 endpoints, then return the root accurate to 6 digits
 */
#include <stdio.h>
#include <math.h>
#define THRESHOLD 0.0001

int sameSign (double, double);
double polynomial(double, int, int, int, int);
double computeRoot(double,double,double,double,int,int,int,int);

int main(void) {
	int    c3, c2, c1, c0; // coefficients of polynomial
	double a, b,           // endpoints
		   pA, pB;         // function values at endpoints
	double m, pM;          // midpoint and function value at midpoint
	printf("Enter coefficients (c3,c2,c1,c0) of polynomial: ");
	scanf("%d %d %d %d", &c3, &c2, &c1, &c0);
	printf("Enter endpoints a and b: ");
	scanf("%lf %lf", &a, &b);

	pA = polynomial(a, c3, c2, c1, c0);
	pB = polynomial(b, c3, c2, c1, c0);
	m = computeRoot(a,b,pA,pB,c3,c2,c1,c0);
	pM = polynomial(m, c3, c2, c1, c0);

	printf("root = %.6f\n", m);
	printf("p(root) = %.6f\n", pM);

	return 0;
}
//This function determines whether 2 given value have the same sign or not
int sameSign(double x, double y){
	if(x>0.0&&y<0.0)return 0;
	if(y>0.0&&x<0.0)return 0;
	return 1;
}

//This function calculates the polynomial of given x and degree of polynomial
double polynomial(double x, int c3, int c2, int c1, int c0){
	return c3*pow(x,3)+c2*pow(x,2)+c1*pow(x,1)+c0;
}
//This funtion computes the root give the a,b boundary and degree of polynomial
double computeRoot(double a, double b, double pA, double pB, int c3, int c2, int c1, int c0){
	double m, pM;
	do{
		m = (a+b)/2.0;
		pM = polynomial(m, c3, c2, c1, c0);
		pA = polynomial(a, c3, c2, c1, c0);
		pB = polynomial(b, c3, c2, c1, c0);
		if(sameSign(pM,pA)==1){
			a=m;
		}else{
			b=m;
		}
	}while(fabs(a-b)>THRESHOLD&&pM!=0);
	if(pM==0)return m;
	m = (a+b)/2.0;
	return m;
}




