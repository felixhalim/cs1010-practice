/**
 * CS1010 AY2017/8 Semester 1 Lab6 Ex1
 * prerequisites.c
 * PROGRAM THAT READ A POSITIVE INTEGER INDICATING
 * THE NUMBER OF MODULES, AND A LIST OF MODULE CODES
 * IT READS A PARTICULAR MODULE CODE
 * AND IF THAT MODULE CODE EXISTS, IT DISPLAYS
 * ALL OF THAT MODULE IN THE SAME ORDER AS THE ENTRY
 * OF MODULE CODES
 * FELIX HALIM
 * T04
 */
#include<stdio.h>
#include<string.h>

#define MAX_MOD  10
#define MAX_LEN  7
int scanModules(char [][MAX_LEN]);
int computePrereq(char [][MAX_LEN], int, char [], char [][MAX_LEN]);
void printPrereq(char [][MAX_LEN], int, char []);

int main(void) {
	int numModules, numPrereq;
	char codes[MAX_MOD][MAX_LEN],         // the list of modules codes
		 target[MAX_LEN],                 // the target module
		 prerequisites[MAX_MOD][MAX_LEN]; // prerequisites of the target module
	numModules = scanModules(codes);
	printf("Choose a module: ");
	scanf("%s", target);
	numPrereq = computePrereq(codes, numModules, target, prerequisites);
	printPrereq(prerequisites, numPrereq, target);
	return 0;
}

// Scan Modules taken and assign it to array of codes
// Return the number of modules taken
int scanModules(char codes[][MAX_LEN]){
	int numOfModules;
	printf("Enter number of modules: ");
	scanf("%d",&numOfModules);
	int i;
	printf("Enter %d modules:\n",numOfModules);
	for(i=0;i<numOfModules;i++){
		scanf("%s", codes[i]);
	}
	return numOfModules;
}

// Function to determine if a module is prerequisite to target module
// Then assign it to array of prerequisites
// Return the number of prerequisite module
int computePrereq(char codes[][MAX_LEN], int numOfModules, char target[MAX_LEN], char prerequisites[][MAX_LEN]){
	int ctrPrereq = 0, i ,j,check,flag=0;
	for(i=0;i<numOfModules;i++){
		check =0;
		if(strcmp(codes[i],target)==0){ //Target module is in list of modules
			flag=1;
		}
		if(codes[i][0]==target[0]&&codes[i][1]==target[1]){ //Pass first check (first two char of modules are the same)
			if(codes[i][2]<target[2]){ //Pass second check (first digit of module codes is less than module target)
				for(j=0;j<3;j++){
					if(codes[i][j+3]<=target[j+3])check++;
				}
				if(check==3){ //Pass third check (the rest digit of module codes are not greater than module target)
					strcpy(prerequisites[ctrPrereq],codes[i]);
					ctrPrereq++;
				}
			}
		}
	}
	if(flag==0) return -1; //Target module is not in list of modules
	return ctrPrereq;
}

// Print the prerequisites
// This function is given. You are NOT to modify it.
void printPrereq(char prerequisites[][MAX_LEN], int numPrereq, char target[]) {
	int i;
	if (numPrereq == -1) {
		printf("No such module %s\n", target);
	}
	else if (numPrereq == 0) {
		printf("No prerequisites for %s\n", target);
	}
	else {
		printf("Prerequisites for %s:", target);
		for (i = 0; i < numPrereq; i++){
			printf(" %s", prerequisites[i]);
		}
		printf("\n");
	}
}



