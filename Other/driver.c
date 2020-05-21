/**
 * CS1010 AY2017/8 Semester 1 Lab6 Ex2
 * driver.c
 * This program calculate the possible routes given an array of gas stations available within distance.
 * FELIX HALIM
 * T04
 */

#include <stdio.h>
#define MAX_STATIONS 20

void readStations(int [], int [], int *, int *);
void printStations(int [], int [], int, int);
int calcPossibleRoutes(int[],int [],int,int,int,int,int);

int main() {
	int distances[MAX_STATIONS];
	int fuels[MAX_STATIONS];
	int totalDist, numStation;
	int possibleRoute;

	readStations(distances, fuels, &totalDist, &numStation); 
	printStations(distances, fuels, totalDist, numStation); 

	possibleRoute = calcPossibleRoutes(distances, fuels, totalDist, numStation, -1, 100, 0);
	//	-1 = current position (petrol[-1] alias starting point)
	//	100 = the current fuel available
	//	0 = current distance covered ( 0 because still in starting point)

	printf("Possible number of routes = %d\n", possibleRoute);

	return 0;
}

// Read the gas stations' distances and available fuel 
// and return the total distance and number of gas stations read.
// Note: Do not change this function
void readStations(int distances[], int fuels[], int *totalDistPtr, int *numStationPtr) {
	int i;

	printf("Enter total distance: ");
	scanf("%d", totalDistPtr);

	printf("Enter number of gas stations: ");
	scanf("%d", numStationPtr);

	printf("Enter distance and amount of fuel for each gas station:\n");
	// gasStation Array will store in such way [dist0, fuel0, dist1, fuel1, dist2, fuel2, ...]
	for (i = 0; i < *numStationPtr; i++) {
		scanf("%d %d", &distances[i], &fuels[i]);
	}
}

// Print total distance and gas stations' distances and fuel
// Note: Do not change this function
void printStations(int distances[], int fuels[], int totalDist, int numStation) {
	int i;

	printf("Total distance = %d\n", totalDist);
	printf("Number of gas stations = %d\n", numStation);
	printf("Gas stations' distances: ");
	for (i = 0; i < numStation; i++) {
		printf("%4d ", distances[i]);
	}
	printf("\n");
	printf("Gas stations' fuel amt : ");
	for (i = 0; i < numStation; i++) {
		printf("%4d ", fuels[i]);
	}
	printf("\n");
}

// Function to calculate the routes
// Return the number of routes possible
int calcPossibleRoutes(int distances[], int fuels[], int totalDist, int numStation, int startStation, int currentFuel, int currentDistance){
	if(currentFuel<0)return 0; // Driver run out of fuel
	else{
		currentFuel+=fuels[i];
		int routes=0;
		if(currentDistance+currentFuel>=totalDist) routes++; //Driver decide to go to destination
		int i;
		for(i=startStation+1;i<numStation;i++){ // Driver try to go to each petrol
			routes+=calcPossibleRoutes(distances,fuels,totalDist,numStation,i,currentFuel-distances[i],currentDistance+distances[i]);
			// i, driver try to go to petrol[i]
			// currentFuel-distances[i]+fuels[i], driver go to petrol[i] so currentFuel is substracted to the distance to go to petrol[i]
			// then add with the fuels available in the petrol
			// currentDistance+distances[i], driver go to petrol[i] so the current distance covered + distances[i] 
		}
		return routes;
	}
}


