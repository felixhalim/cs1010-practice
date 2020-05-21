// CS1010 AY2012/3 Semester 1 PE2 Ex1
//
// password.c
// This program checks whether a new password satisfies
// corresponding rules or not.
//
// Name: FELIX HALIM 
// Matriculation number: A0200664N 
// plab account-id: T04
// Discussion group: T04
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LEN 15

int isValidPassword(char [], char [], char [], char []);

int main(void) {
	char domain[LEN+1], userID[LEN+1], 
		 oldPasswd[LEN+1], newPasswd[LEN+1], confirmPasswd[LEN+1];
	printf("Domain: ");
	scanf("%s", domain);
	printf("UserID: ");
	scanf("%s", userID);
	printf("Old password: ");
	scanf("%s", oldPasswd);
	printf("New password: ");
	scanf("%s", newPasswd);
	printf("Confirm new password: ");
	scanf("%s", confirmPasswd);
	if ( isValidPassword(userID, oldPasswd, newPasswd, confirmPasswd) )
		printf("Password changed successfully!\n");
	else
		printf("Error: Invalid userID or password!\n");
	return 0;
}
// Check whether a new password is valid
int isValidPassword(char userID[], char oldPasswd[],
		char newPasswd[], char confirmPasswd[]) {
	// 1. New password must be at least 8 characters in length
	int len = strlen(newPasswd);
	if(len<8)return 0;
	// 2. New password must be complex
	int lower=0, upper=0, i;
	for(i = 0; i<len;i++){
		if(isalnum(newPasswd[i])||newPasswd[i]=='_'){
			if(isupper(newPasswd[i]))upper++;
			if(islower(newPasswd[i]))lower++;
		}else return 0;
	}
	if(lower<1||upper<1)return 0;
	// 3. The new password must not contain UserID
	char* find = strstr(newPasswd,userID);
	if(find!=NULL)return 0;
	// 4. The confirmation for the new password must match the new password.
	if(strcmp(newPasswd,confirmPasswd)!=0)return 0;
	// 5. The new password must not be the same as old password. 
	if(strcmp(newPasswd,oldPasswd)==0)return 0;
	return 1; // stub, to be replaced by your code
}
// You may write additional functions below if needed.
// However every function must be preceeded with a function description.

