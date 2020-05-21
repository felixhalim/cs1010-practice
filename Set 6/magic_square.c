#include <stdio.h>
#define MAX_SIZE 15
void printMagic(int [][MAX_SIZE], int);
void generateMagic(int [][MAX_SIZE], int);
int main(void) {
	int magic[MAX_SIZE][MAX_SIZE] = { {0} }; 
	int size; 
	printf("Enter size of matrix: ");
	scanf("%d", &size);
	printf("%d\n", size);
	generateMagic(magic, size);
	printMagic(magic, size);
	return 0;
}
// To generate the magic square
void generateMagic(int arr[][MAX_SIZE], int size) {
	int mid = size/2;
	int n=1;
	arr[0][mid] = n;
	n++;
	int ptrRow, ptrCol, oriRow, oriCol;
	ptrRow = oriRow = 0, ptrCol = oriCol = mid;
	while(n<=size*size){
		ptrRow--;
		ptrCol++;
		if(ptrRow<0) ptrRow=size-1;
		if(ptrCol>=size) ptrCol=0;
		if(arr[ptrRow][ptrCol]==0){
			arr[ptrRow][ptrCol]=n;
		}else{
			ptrRow=oriRow+1;
			ptrCol=oriCol;
			if(ptrRow>=size)ptrRow=0;
			arr[ptrRow][ptrCol]=n;
		}
		oriRow=ptrRow;
		oriCol=ptrCol;
		n++;
	}

}
// To print the magic square
void printMagic(int arr[][MAX_SIZE], int size) {
	int row, col;
	for (row=0; row<size; row++) {
		for (col=0; col<size; col++) 
			printf("%5d", arr[row][col]);
		printf("\n");
	}
}

