/**
 *CS1010 AY2017/8 Semester 1 Lab4 Ex1
 * nanotable1.c
 * A PROGRAM TO COMPUTE
 * SUM, AVERAGE, AND RANK OF
 * TABLE OF STUDENT SCORE
 * FELIX HALIM
 * T04
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#define TRUE 1
#define MAX_COMMAND_LENGTH 100
#define MAX_ENTRY 100
/* Function prototypes */
void print_help();
void print_table_empty();
void shift(int*,int*,int,int);
void insert_table(int*,int*,int*);
int sum(int*,int);
double ave(int*,int);
void rank(int*,int*,int);
int main(void) {

	// The string for input command, do not modify...
	char input[MAX_COMMAND_LENGTH];

	int studentScore[MAX_ENTRY];
	int studentID[MAX_ENTRY];

	int size=0;
	int *p_size = &size;

	// print welcome information
	printf("Welcome to Nanotable!\n");
	printf("Type \"help\" for more information...\n");

	while (TRUE) {
		printf("Waiting for command...\n");
		scanf("%s", input);

		if (strcmp(input,"help") == 0) {
			print_help();
		} else if (strcmp(input,"exit") == 0){
			printf("See you!\n");
			break;
		} else if (strcmp(input,"sum") == 0) {
			int sumOfTable = sum(studentScore,size);
			if (size==0) {
				print_table_empty();
			} else {
				// TO BE IMPLEMENTED
				printf("The sum of score is %d\n", sumOfTable);
			}
		} else if (strcmp(input,"ave") == 0) {
			int averageOfTable = round(ave(studentScore,size));
			if (size==0) {
				print_table_empty();
			} else {
				// TO BE IMPLEMENTED
				printf("The average of score is %d\n", averageOfTable);
			}
		} else if (strcmp(input,"insert") == 0) {
			insert_table(studentScore,studentID,p_size);
		} else if (strcmp(input,"init") == 0) {
			*p_size=0;
			printf("Initializing table...\n");
		} else if (strcmp(input,"rank") == 0) {
			if (size==0) {        
				print_table_empty();
			} else {
				// TO BE IMPLEMENTED
				rank(studentID,studentScore,size);
			}
		} else {
			printf("No such command: %s, please input command again!\n", input);
		}
	}
	return 0;
}
// This function prints the help information
void print_help() {
	printf("Commands available: insert, init, sum, ave, rank, help, exit\n");
}
//Function to print that table is empty
void print_table_empty(){
	printf("The table is empty\n");
}
//Function to shift all elements to right by one
//arr[1]->arr[2]
//arr[2]->arr[3]
//etc.
void shift(int *id, int *score, int i, int size){
	int j;
	for(j=size;j>i;j--){
		score[j]=score[j-1];
		id[j]=id[j-1];
	}
}
//Function to input element to the table
//elements inside the table is always sorted
void insert_table(int *score, int *id, int *size){
	int tempScore, tempID, tempSize = *size;
	printf("Please input the student's ID...\n");
	scanf("%d",&tempID);
	printf("Please input the student's score...\n");
	scanf("%d",&tempScore);

	int i, inserted =0;
	for(i=0;i<tempSize;i++){
		if(tempScore<score[i]){
			shift(id,score,i,tempSize);
			score[i]=tempScore;
			id[i]=tempID;
			inserted=1;
			break;
		}else if(tempScore == score[i] && tempID < id[i]){
			shift(id,score,i,tempSize);
			score[i]=tempScore;
			id[i]=tempID;
			inserted=1;
			break;
		}
	}
	if(!inserted){
		score[tempSize]=tempScore;
		id[tempSize]=tempID;
	}
	*size=tempSize+1;
}
//Function to compute the sum score in the table
int sum(int *score, int size){
	int total=0;
	int i;
	for(i=0;i<size;i++)total+=score[i];
	return total;
}
//Function to compute average score in the table
double ave(int *score, int size){
	double average = (double)sum(score,size)/(double)size;
	return average;
}

//Function to return the score based on inputted ranking
void rank(int* id, int*score, int size){
	int tempRank;
	while(TRUE){
		printf("Please input the rank (1 - %d)...\n",size);
		scanf("%d",&tempRank);
		if(tempRank<=size && tempRank>0){
			printf("ID: %d, Score: %d\n",id[tempRank-1],score[tempRank-1]);	
			break;
		}
		printf("Invalid rank: %d\n",tempRank);
	}
}
