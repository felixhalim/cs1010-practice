/**
 * CS1010 AY2019/20 Semester 1 Lab1 Ex2
 * box.c
 * This program calculates the surface area and diagonal of 
 * cuboid, given the length, width, and height
 * FELIX HALIM
 * T04
 */

#include<stdio.h>
#include<math.h>

int compute_surface_area(int length, int width, int height);
double compute_diagonal(int length, int width, int height);

int main(){
	int length, width, height;

	printf("Enter length: ");
	scanf("%d",&length);

	printf("Enter width : ");
	scanf("%d",&width);

	printf("Enter height: ");
	scanf("%d",&height);

	printf("Surface area = %d",compute_surface_area(length,width,height));
	printf("\nDiagonal = %.2lf\n",compute_diagonal(length,width,height));

	return 0;
}

//Compute the surface area with basic formula
int compute_surface_area(int length, int width, int height){
	int surfaceArea = 2*(length*width+width*height+height*length);
	return surfaceArea;
}

//Compute the diagonal with the Pythagoras theorem
double compute_diagonal(int length, int width, int height){
	double diagonal = sqrt(pow(length,2)+pow(width,2)+pow(height,2));
	return diagonal;
}