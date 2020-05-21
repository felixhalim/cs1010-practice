/**
 * CS1010 AY2019/20 Semester 1 Lab1 Ex3
 * packing.c
 * This program calculates the amount of maximum
 * slabs that can be packed onto the tray
 * FELIX HALIM
 * T04
 */

#include <stdio.h>

int compute_max_slabs(int trayY, int trayX, int slabY, int slabX);

int main(void) {
	int max_slabs, trayX, trayY, slabX, slabY;

	printf("Enter dimension of tray: ");
	scanf("%d %d", &trayX, &trayY);

	printf("Enter dimension of slab: ");
	scanf("%d %d", &slabX, &slabY);

	max_slabs = compute_max_slabs(trayY, trayX, slabY, slabX);
	printf("Maximum number of slabs = %d\n", max_slabs);

	return 0;
}

//Compute the number of maximum slabs
int compute_max_slabs(int trayY, int trayX, int slabY, int slabX){
	int first = (trayY/slabY)*(trayX/slabX);
	int second = (trayY/slabX)*(trayX/slabY);

	if(first>second){
		return first;
	}
	return second;
}

