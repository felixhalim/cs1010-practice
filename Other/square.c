/**
 * CS1010 AY2017/8 Semester 1 Lab5 Ex1
 * square.c
 * Given the size of a square and the values in
 * in the square, this program determines whether 
 * the given square is a semi-magic square.
 * FELIX HALIM
 * T04
 */
#include <stdio.h>
#define MAXSIZE 9

int scanSquare(int [][MAXSIZE]);
int hasOccured(int, int[], int);
int isSemiMagic(int [][MAXSIZE], int);

int main(void) { 
	int arr[MAXSIZE][MAXSIZE];
	int size = scanSquare(arr);
	if(isSemiMagic(arr,size)){
		printf("It is a semi-magic square.\n");  
	}else{
		printf("It is not a semi-magic square.\n");
	}
	return 0;
}

// Read in size of square and values in the square. 
// Return the size of square.
int scanSquare(int square[][MAXSIZE]) {
	int r, c, size;
	printf("Enter size of square: ");
	scanf("%d", &size);
	printf("Enter values in the square: \n");
	for (r=0; r<size; r++) {
		for (c=0; c<size; c++) {
			scanf("%d", &square[r][c]);
		}
	}
	return size;
}

//Function to determine if given number
//has occured or not, if it has occured
//return 1 if it has occured
//return 0 and change the status to 1
//If given number is greater than size*size
//or less than 1 return 1 (out of bound)
int hasOccured(int x, int arr[], int size){
	if(x>(size*size)||x<1)return 1;
	if(arr[x-1]==0){
		arr[x-1]=1;
		return 0;
	}
	return 1;
}

//Function to determine if a given square is a semi-magic
//square or not, return 1 if yes, otherwise 0
int isSemiMagic(int square[][MAXSIZE], int size){
	int number[MAXSIZE*MAXSIZE]={0};
	int pivot = 0;
	int r, c, temp;
	for(c=0;c<size;c++){
		if(!hasOccured(square[0][c],number,size)){
			pivot+=square[0][c];
		}else{
			return 0;
		}
	}
	//Check horizontal
	for(r=1;r<size;r++){
		temp=0;
		for(c=0;c<size;c++){
			if(hasOccured(square[r][c],number,size))return 0;
			temp+=square[r][c];
		}
		if(temp!=pivot)return 0;
	}
	//Check vertical
	for(c=0;c<size;c++){
		temp=0;
		for(r=0;r<size;r++){
			temp+=square[r][c];
		}
		if(temp!=pivot)return 0;
	}
	return 1;
}
