// ilink.c
#include <stdio.h>
#define MAXSIZE 10
void printArr(int [][MAXSIZE], int);
int isDuplicate(int,int,int [MAXSIZE*MAXSIZE], int [MAXSIZE*MAXSIZE], int);
void iSolitude(int [][MAXSIZE], int);
void uFriend(int [][MAXSIZE], int);
int main() {
	int friendArr[MAXSIZE][MAXSIZE] = { {0} };
	int size, pairsNum;
	int i, j, k;
	printf("Read in the number of users: ");
	scanf("%d", &size);
	printf("There are %d users, indexed from 0 to %d.\n", size, size-1);
	printf("Enter the number of pairs of direct friends: ");
	scanf("%d", &pairsNum);
	printf("Enter actual pairs of direct friends:\n");
	for (k = 0; k < pairsNum; k++) {
		scanf("%d %d", &i, &j);
		friendArr[i][j] = 1;
	}
	printArr(friendArr,size);
	for (i = 0; i < size; i++) {
		friendArr[i][i] = 1;
		for (j = i+1; j < size; j++) {
			if (friendArr[i][j] != friendArr[j][i]) {
				friendArr[i][j] = 1; 
				friendArr[j][i] = 1;
			}
		}
	}
	printf("The friendship matrix is:\n");
	printArr(friendArr, size);
	iSolitude(friendArr, size);
	uFriend(friendArr, size);
	return 0;
}
void printArr(int arr[][MAXSIZE], int size) {
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++)
			printf("%3d", arr[i][j]);
		printf("\n");
	}
}
void iSolitude(int arr[][MAXSIZE], int size){
	int i,j;
	int minFriend[MAXSIZE]={0};
	int sizeMinFriend, ctr;
	int min=1000;
	for(i=0;i<size;i++){
		ctr = 0;
		for(j=0;j<size;j++){
			ctr+=arr[i][j];
		}
		if(ctr<min){
			sizeMinFriend=0;
			minFriend[sizeMinFriend]=i;
			sizeMinFriend++;
			min=ctr;
		}else if(ctr==min){
			minFriend[sizeMinFriend]=i;
			sizeMinFriend++;
		}
	}
	printf("The least number of friends found is %d\n",min);
	for(i=0;i<sizeMinFriend;i++){
		printf("User %d has least number of friends\n",minFriend[i]);
	}
}
int isDuplicate(int key1, int key2, int arr[MAXSIZE*MAXSIZE], int arr2[MAXSIZE*MAXSIZE], int size){
	int i;
	for(i=0;i<size;i++)if((key1==arr2[i]&&key2==arr[i])||(key1==arr[i]&&key2==arr2[i]))return 1;
	return 0;
}
void uFriend(int arr[][MAXSIZE], int size){
	int fof[MAXSIZE*MAXSIZE]={0};
	int fof2[MAXSIZE*MAXSIZE]={0};
	int sizefof=0;
	int i,j,k;
	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			if(arr[i][j]==0&&i!=j)
				for(k=0;k<size;k++)
					if(arr[i][k]==1&&arr[j][k]==1&&!isDuplicate(i,j,fof,fof2,sizefof+1)){
						fof[sizefof]=i;
						fof2[sizefof]=j;
						sizefof++;
					}
	for(i=0;i<sizefof;i++){
		printf("(%d,%d) has a friend-of-friend relation.\n",fof[i],fof2[i]);
	}
}
