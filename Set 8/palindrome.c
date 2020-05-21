// palindrome.c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLEN 20
void mod(char[]);
int isPalindrome(char []);
int main(void) {
	char word[MAXLEN+1];
	printf("Enter word: ");
	scanf("%s",word);
	if (isPalindrome(word))
		printf("\"%s\" is a palindrome.\n",word);
	else
		printf("\"%s\" is not a palindrome.\n",word);
	return 0;
}
void mod(char x[]){
	int i =0;
	for(i=0;i<MAXLEN;i++){
		x[i]=tolower(x[i]);
		if(x[i]=='\0')break;
	}
}
// Return 1 if str is a palindrome, otherwise return 0.
int isPalindrome(char x[]) {
	char str[MAXLEN+1];
	strcpy(str,x);
	mod(str);
	int len = strlen(str);
	int i;
	for(i=0;i<len/2;i++){
		if(str[i]!=str[len-1-i])return 0;
	}
	return 1;
}

