/**
 * CS1010 AY2017/8 Semester 1 Lab5 Ex2
 * Given a 12x12 integer array, fill it with integers, and
 * find the longest sequence of a digit that appears in 
 * the array horizontally, vertically or diagonally.
 * FELIX HALIM
 * T04
 */

#include <stdio.h>
#define DIM 12

int scanBoard(int [][DIM]);
void checkLength(int,int*,int*,int*,int,int);
int search(int, int [][DIM], int*, int*);

int main(void) {
	int board[DIM][DIM] = { {0} };
	int search_digit;     
	int length;           // length of the longest sequence of search digit
	int bestRow, bestCol; // where the longest sequence of search digit starts in the board
	search_digit = scanBoard(board);
	length = search(search_digit,board,&bestRow,&bestCol);
	if (length > 0) {
		printf("Length of longest sequence = %d\n", length); 
		printf("Start at (%d,%d)\n", bestRow, bestCol);      
	}
	else
		printf("No such sequence.\n");
	return 0;
}

//Function that read data into the board,
//and search the digit, and return the
//search digit (key)
int scanBoard(int arr[][DIM]) {
	int r,c;
	for(r=0;r<DIM;r++)
		for(c=0;c<DIM;c++)
			scanf("%d",&arr[r][c]);
	int key;
	scanf("%d",&key);
	return key;
}
//Check if tempLength is greater than length
//If yes then assign the start position and length
//If no do nothing
void checkLength(int tempLength, int*length, int*row, int*col, int r, int c){
	if(tempLength>*length){
		*length = tempLength;
		*row = r;
		*col = c;
	}
}
//Function that return the longest length
//of sequence of the search digit in the
//board, then the start posititon of the
//sequence (row and col)
int search(int key, int arr[][DIM], int*row, int*col) {
	int r,c,length=0,tempLength;
	int tempRow=-1;
	int tempCol=-1;
	for(r=0;r<DIM;r++){
		for(c=0;c<DIM;c++){
			tempLength=0;
			if(arr[r][c]==key){
				//Cek horizontal
				int i,j;
				for(i=c;i<DIM;i++){
					if(arr[r][i]==key)tempLength++;
					else break;
				}
				checkLength(tempLength,&length,&tempRow,&tempCol,r,c);
				tempLength = 0;
				//Cek vertical
				for(i=r;i<DIM;i++){
					if(arr[i][c]==key)tempLength++;
					else break;
				}
				checkLength(tempLength,&length,&tempRow,&tempCol,r,c);
				tempLength = 0;
				//Cek Diagonal
				for(i=r,j=c;i<DIM && j<DIM;i++,j++){
					if(arr[i][j]==key)tempLength++;
					else break;
				}
				checkLength(tempLength,&length,&tempRow,&tempCol,r,c);
				tempLength=0;
			}
		}
	}
	*row = tempRow;
	*col = tempCol;
	return length;
}

