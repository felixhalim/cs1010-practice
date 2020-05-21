#include <stdio.h>
#define MAX_ROW 100
#define MAX_COL 100

int find(int, int[][MAX_COL], int*, int*, int ,int);
int rescueRobot(int [][MAX_COL], int, int, int);

int main(){
	int row, col, level, i, j;
	int land[MAX_ROW][MAX_COL];

	printf("Enter dimensions of the land: ");
	scanf("%d %d",&row,&col);

	printf("Enter elevations: \n");

	for(i=0;i<row;i++) 
		for(j=0;j<col;j++) 
			scanf("%d",&land[i][j]);

	printf("Enter flood level: ");	
	scanf("%d",&level);

	int ans  = rescueRobot(land,row,col, level);
	printf("Number of robots to be rescued: %d\n",ans); // Incomplete

	return 0;
}

int find(int n, int arr[][MAX_COL], int *r, int *c, int row, int col){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(arr[i][j]==n){
				*r = i;
				*c = j;
				return 1;
			}
		}
	}
	return 0;
}

int rescueRobot(int land[][MAX_COL],int r, int c, int l){
	int countRobot[MAX_ROW][MAX_COL];
	int i,j;
	for(i = 0 ; i < r;i++)
		for(j=0;j<c;j++)
			countRobot[i][j]=1;
	int nilaiMax=-1,nilaiMin=9999;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(land[i][j]>nilaiMax)nilaiMax = land[i][j];
			if(land[i][j]<nilaiMin)nilaiMin = land[i][j];
		}
	}
	int n = nilaiMin;
	int nRow;
	int nCol;
	while(n<=nilaiMax){
		//Cari posisi n
		if(find(n,land,&nRow,&nCol,r,c)){
			int mRow=nRow, mCol=nCol;
			if(nRow-1>=0&&land[nRow-1][nCol]>land[mRow][mCol]){
				mRow = nRow-1;
				mCol = nCol;
			}
			if(nRow+1<r&&land[nRow+1][nCol]>land[mRow][mCol]){
				mRow = nRow +1;
				mCol = nCol;
			}
			if(nCol+1<c&&land[nRow][nCol+1]>land[mRow][mCol]){
				mRow = nRow;
				mCol = nCol+1;
			}
			if(nCol-1>=0&&land[nRow][nCol-1]>land[mRow][mCol]){
				mRow = nRow;
				mCol = nCol-1;
			}
			if(mRow!=nRow||mCol!=nCol){
				countRobot[mRow][mCol]+=countRobot[nRow][nCol];
				countRobot[nRow][nCol]=0;
			}
		}
		n++;
	}
	int counter =0;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(countRobot[i][j]>0&&land[i][j]<l)counter+=countRobot[i][j];
		}
	}
	return counter;
}
