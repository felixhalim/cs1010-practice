#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 100

int sumOf(char[]);

int main(){
	char input[MAX_SIZE];
	printf("Enter input: ");
	scanf("%s",input);
	int len = strlen(input);
	if(input[len-1]=='\n'){
		input[len-1] = '\0';
	}
	printf("Sum = %d\n",sumOf(input));
	return 0;
}

int sumOf (char str[]){
	int i =0, len = strlen(str);
	int sum=0;
	for(i=0;i<len;i++){
		if(isdigit(str[i]))sum+=(str[i]-'0');
	}
	return sum;
}
