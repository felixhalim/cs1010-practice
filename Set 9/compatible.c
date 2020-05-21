// CS1010 AY2013/4 Semester 1
// PE2 Ex1: compatible.c
// Name: FELIX HALIM 
// Matriculation number: A0200664N 
// plab-id: P05
// Discussion group: T04
// Given two names, strike off matching letters in the names,
// find the number of remaining letters in the names, and 
// determines if the names are compatible.
#include <stdio.h>
#include <ctype.h>
#include <string.h>
// Name has at most 35 characters
#define MAXLEN 36
void readName(char[]);
int contains(char,char[]);
void match(char[],char[],int*,int*);
// Fill in your function prototypes below
int main(void) {
	char name1[MAXLEN], name2[MAXLEN];
	int remain1=0,   // number of remaining characters in name1 
		remain2=0;   // and name2 after matching
	printf("Enter 2 names below:\n"); // given, do not remove/change this line
	readName(name1);                  // given, do not remove/change this line
	readName(name2);                  // given, do not remove/change this line

	match(name1,name2,&remain1,&remain2);

	printf("Number of letters remaining in 1st name = %d\n", remain1);
	printf("Number of letters remaining in 2nd name = %d\n", remain2);
	if(remain1%2==remain2%2){
		printf("The names are compatible.\n");
	}else{
		printf("The names are not compatible.\n");
	}
	return 0;
}

//Function to read string (name)
void readName(char name[]){
	fgets(name,MAXLEN,stdin);
	int len = strlen(name);
	if(name[len-1]=='\n')
		name[len-1]='\0';
}
// To determine if a character of name1 is in name2
int contains(char x, char name2[]){
	int len = strlen(name2);
	int i;
	for(i=0;i<len;i++)
		if(x==tolower(name2[i])){
			name2[i]='@';
			return 1;
		}
	return 0;
}

//Function to find the remainder of each name after striking out
//common letter
void match(char name1[],char name2[], int*r1, int*r2){
	int i;
	int len = strlen(name1);
	int len2 = strlen(name2);
	for(i=0;i<len;i++){
		if(name1[i]!=' '&&contains(tolower(name1[i]),name2)){
			name1[i]='@';
		}
	}
	for(i=0;i<len;i++)
		if(isalpha(name1[i]))
			*r1+=1;
	for(i=0;i<len2;i++)
		if(isalpha(name2[i]))
			*r2+=1;
}

