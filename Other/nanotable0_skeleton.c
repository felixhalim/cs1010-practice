/**
 * CS1010 AY2019/20 Semester 1 Lab2 Task1
 * nanotable0_skeleton.c
 * This program calculates the average and sum
 * of numbers given by implementing REPL style
 * FELIX HALIM
 * T04
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define COMMAND_HELP 0
#define COMMAND_EXIT 1
#define COMMAND_SUM 2
#define COMMAND_AVE 3
#define COMMAND_INVALID 4

/* Function prototypes */
int suffixOf(int);

int parse_command();

int check_command(char* input);

void print_help();

int calculate_sum(int);

int simple_sum();

int simple_average();

int main() {
	// print welcome information
	printf("Welcome to Nanotable!\n");
	printf("Type \"help\" for more information...\n");

	parse_command();

	return 0;
}

// This function take integer x as input and integer idx as output
// INPUT OUTPUT
// 1		0
// 2		1
// 3		2
// 4		3
// 5		3
// Basically the output is the index of corresponding suffix type.
// 0 is "st"
// 1 is "nd"
// 2 is "rd"
// 3 is "th"
int suffixOf(int x){
	int idx;
	if(x%10==1&&x/10%10!=1){
		idx=0;
	}else if(x%10==2&&x/10%10!=1){
		idx=1;
	}else if(x%10==3&&x/10%10!=1){
		idx=2;
	}else{
		idx=3;
	}
	return idx;
}

// TO BE IMPLEMENTED: this should work in a REPL style
int parse_command() {
	char tmp_command[100] = "";
	int command_code;

	do{
		printf("Waiting for command...\n");
		scanf("%s", tmp_command);

		command_code = check_command(tmp_command);    

		if (command_code == COMMAND_HELP) {
			print_help();
		}
		else if (command_code == COMMAND_EXIT) {
			printf("See you!\n");
		}
		else if (command_code == COMMAND_SUM) {
			simple_sum();
		}
		else if (command_code == COMMAND_AVE) {
			simple_average();
		}
		else {
			// others
			printf("No such command: %s, please input command again!\n", tmp_command);
		}
	}while(command_code != COMMAND_EXIT);
	return 0;
}
// This function takes integer n as input and integer sum as output
// Integer n indicates the number of total value to be inputted
// Integer sum indicates the summation of the value inputted
// Furthermore the i suffix corresponds to the correct
// ordinal suffix with the help of function suffixOf
int calculate_sum(int n){
	int sum = 0, i;
	for(i = 0 ; i<n;i++){	
		char *suffix;
		switch(suffixOf(i+1)){
			case 0:
				suffix = "st";
				break;
			case 1:
				suffix = "nd";
				break;
			case 2:
				suffix = "rd";
				break;
			case 3:
				suffix = "th";
				break;
			default:
				suffix = "NA";
				break;
		}
		printf("Please input the %d%s number:\n",(i+1),suffix);
		int temp;
		scanf("%d",&temp);
		sum+=temp;
	}
	return sum;
}

// TO BE IMPLEMENTED: simple_sum and simple_average
// This function calculates the sum of numInt integer(s)
// with the help of function calculate_sum
int simple_sum() {
	int numInt;
	printf("Please indicate the number of integers:\n");
	scanf("%d",&numInt);
	int sum = calculate_sum(numInt);
	printf("sum is %d\n", sum);
	return 0;
}

// This function calculates the average of numInt integer(s) 
// with the help of function calculate_sum
int simple_average() {
	int numInt;
	printf("Please indicate the number of integers:\n");
	scanf("%d",&numInt);
	int sum = calculate_sum(numInt);
	int ave = round((float)sum/(float)numInt);
	printf("average is %d\n", ave);
	return 0;
}

// DO NOT MODIFY THE FOLLOWING PART!

// This function takes a command as input and returns an integer as output.
/* INPUT    OUTPUT
   help     0
   EXIT     1
   SUM      2
   AVE      3
   others   4
 */
int check_command(char* input) {
	if (strcmp(input,"help") == 0) {
		return COMMAND_HELP;
	}
	else if (strcmp(input,"exit") == 0) {
		return COMMAND_EXIT;
	}
	else if (strcmp(input,"sum") == 0) {
		return COMMAND_SUM;      
	}
	else if (strcmp(input,"ave") == 0) {
		return COMMAND_AVE;
	}
	else {
		return COMMAND_INVALID;
	}
}

// This function prints the help information
void print_help() {
	printf("Commands available: sum, ave, help, exit\n");
}

