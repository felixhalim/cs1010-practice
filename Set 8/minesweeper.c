// minesweeper.c
#include <stdio.h>
#include <string.h>
#define MINE '*'       // a mine-filled square
#define L1_ROWS 8      // number of rows for level-1 grid
#define L1_COLS 8      // number of columns for level-1 grid
#define L2_ROWS 12     // number of rows for level-2 grid
#define L2_COLS 16     // number of columns for level-2 grid
#define L3_ROWS 16     // number of rows for level-3 grid
#define L3_COLS 30     // number of columns for level-3 grid

int countBomb(int,int,char[L3_ROWS+1][L3_COLS+1],int,int);
void fill(int [L3_ROWS+1][L3_COLS+1],char[L3_ROWS+1][L3_COLS+1],int,int);
void scan_mines(char[L3_ROWS+1][L3_COLS+1], int);

int main(void) {
	int level, rows, cols;
	int rows_limit[3] = {L1_ROWS, L2_ROWS, L3_ROWS};
	int cols_limit[3] = {L1_COLS, L2_COLS, L3_COLS};
	scanf("%d\n", &level);
	rows = rows_limit[level-1];
	cols = cols_limit[level-1];
	char grid[L3_ROWS+1][L3_COLS+1];
	scan_mines(grid,rows);

	int map[L3_ROWS+1][L3_COLS+1];
	fill(map,grid,rows,cols);
	int i,j;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			printf(" %d",map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int countBomb(int i,int j, char grid[L3_ROWS+1][L3_COLS+1], int rows, int cols){
	int ctr=0;
	if(i-1>=0&&grid[i-1][j]=='*')ctr++;
	if(i+1<rows&&grid[i+1][j]=='*')ctr++;
	if(j-1>=0&&grid[i][j-1]=='*')ctr++;
	if(j+1<cols&&grid[i][j+1]=='*')ctr++;
	if(j-1>=0&&i-1>=0&&grid[i-1][j-1]=='*')ctr++;
	if(j-1>=0&&i+1<rows&&grid[i+1][j-1]=='*')ctr++;
	if(j+1<cols&&i+1<rows&&grid[i+1][j+1]=='*')ctr++;
	if(j+1<cols&&i-1>=0&&grid[i-1][j+1]=='*')ctr++;

	return ctr;
}

void fill(int map [L3_ROWS+1][L3_COLS+1], char grid[L3_ROWS+1][L3_COLS+1], int rows,int cols){
	int i,j;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			if(grid[i][j]=='*')map[i][j]=9;
			else{
				map[i][j]=countBomb(i,j,grid,rows,cols);
			}
		}
	}
}
// Read the grid for minefield
void scan_mines(char grid[L3_ROWS+1][L3_COLS+1], int rows) {
	int r;
	for (r=0; r<rows; r++) {
		scanf("%s", grid[r]); // Alternatively: gets(grid[r])
	}
}

