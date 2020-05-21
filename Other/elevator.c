/**
 * CS1010 AY2017/8 Semester 1 Lab6 Ex3
 * elevator.c
 * PROGRAM THAT SIMULATES THE RUNNING OF THE ELEVATORS AND PRINTS
 * THE LAST FLOOR, USAGE, AND PASSENGER
 * FELIX HALIM
 * T04
 */

#include <stdio.h>
#include <string.h>
#define CAPACITY 15
#define MAX_LEN 21
#define MAX_ELEVATORS 5

typedef struct {
	int floor;
	int passenger;
	int usage;
} elevator_t;

void setupElevators(elevator_t [], int);
void readSequences(char [][MAX_LEN], int);
void runElevators(elevator_t [], char [][MAX_LEN], int);
void goToFloor(elevator_t *pwd, int, int);
void printElevators(elevator_t [], int size);
int mostUsedElevator(elevator_t [], int);

// This function is given. You are NOT to modify it.
int main(void){
	int size;
	elevator_t elevators[MAX_ELEVATORS];
	char sequences[MAX_ELEVATORS][MAX_LEN];

	printf("Enter number of elevators: ");
	scanf("%d", &size);

	setupElevators(elevators, size);
	readSequences(sequences, size);

	runElevators(elevators, sequences, size);

	printElevators(elevators, size);
	printf("Most used elevator: %d\n", mostUsedElevator(elevators, size));

	return 0;
}

// Function to initialize all the elevator information
void setupElevators(elevator_t elevators[], int size){
	int i;
	for(i=0;i<size;i++){
		elevators[i].usage = 0;
		elevators[i].passenger = 0;
		elevators[i].floor = 0;
	}
}	

// Read in the sequenceIs of floors the elevators go to.
// This function is given. You are NOT to modify it.
void readSequences(char sequences[][MAX_LEN], int size){
	int i;

	for (i = 0; i<size; i++){
		printf("Enter sequence for elevator %d: ", i+1);
		scanf("%s", sequences[i]);
	}
}

// Simulate the elevator running
// for each elevator with the given sequence
void runElevators(elevator_t elevators[], char sequences[][MAX_LEN], int size){
	int i,j,seqLen;
	int prevFloor;
	for(i=0;i<size;i++){
		prevFloor = 0;
		seqLen = strlen(sequences[i]);
		for(j=0;j<seqLen;j++){
			goToFloor(&elevators[i],prevFloor,sequences[i][j]-'0');
			prevFloor = sequences[i][j]-'0';
		}
	}
}

//If go to lower level people go out
//If go to higher level people go in
void goToFloor(elevator_t *elevator, int prevFloor, int floor){
	if(prevFloor<floor){
		if(elevator->passenger+floor>15)elevator->passenger = 15;
		else elevator->passenger += floor;
	}else{
		if(elevator->passenger-floor<0){
			elevator->usage += elevator->passenger;
			elevator->passenger =0;
		}else{
			elevator->passenger -= floor;
			elevator->usage += floor;
		}
	}
	elevator->floor = floor;
}

//Print the elevator information
void printElevators(elevator_t elevators[], int size){
	int i;
	for(i=0;i<size;i++){
		printf("Elevator %d:\n",i+1); 
		printf("Floor: %d\n", elevators[i].floor);
		printf("Number of passengers: %d\n", elevators[i].passenger);
		printf("Usage: %d\n", elevators[i].usage);
	}
}

//Print the most used elevator, if same print the 
//Elevator with lower code
int mostUsedElevator(elevator_t elevators[], int size){
	int i, maxUsage=0;
	for(i=1;i<size;i++){
		if(elevators[i].usage>elevators[maxUsage].usage)maxUsage = i;
	}

	return maxUsage+1;
}


