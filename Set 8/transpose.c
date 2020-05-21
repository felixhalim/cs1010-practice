// transpose.c
#include <stdio.h>
#include <string.h>
#define MAX_ROWS 10      // maximum number of rows
#define MAX_COLS 10     // maximum number of columns 
#define MAX_LENGTH 100   // maximum number of characters in the message & result
int encrypt(int, int, char [], char []);
int decrypt(int, int, char [], char []);
int main(void) {
	int status;
	printf("Enter 1 for encryption, 2 for decryption: ");
	scanf("%d",&status);
	int r,c;
	printf("Enter dimensions of a 2D array: ");
	scanf("%d %d",&r,&c);
	char dump;
	scanf("%c",&dump);
	char message[MAX_LENGTH];
	char result[MAX_LENGTH];
	printf("Enter message: ");
	fgets(message,MAX_LENGTH+1,stdin);
	int len = strlen(message);
	if(message[len-1]=='\n')
		message[len-1]='\0';
	if(status==1){
		if(encrypt(r,c,message,result)){
			printf("Encrypted message: %s\n", result);
		}else{
			printf("Encryption failed.\n");
		}
	}else{
		if(decrypt(r,c,message,result)){
			printf("Decrypted message: %s\n", result);
		}else{
			printf("Decryption failed.\n");
		}
	}
	return 0;
}
// Encrypt a message based on transposition algorithm
int encrypt(int rows, int cols, char message[], char result[]){
	int len = strlen(message);
	if(len>rows*cols)return 0;
	int i, j, k=0;
	char temp[rows][cols];
	//Assigning value from col to col
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			if(k>=len)
				temp[i][j]='@';
			else
				temp[i][j]=message[k];
			k++;
		}
	}
	k=0;
	//Reading value from row to row
	for(j=0;j<cols;j++){
		for(i=0;i<rows;i++){
			result[k]=temp[i][j];
			k++;
		}
	}
	result[k]='\0';
	return 1;
}
// Decrypt a message based on transposition algorithm
int decrypt(int rows, int cols, char message[], char result[]){
	int len = strlen(message);
	if(len!=rows*cols)
		return 0;
	int i,j, k=0;
	char temp[rows][cols];
	//Assigning value from row to row
	for(j=0;j<cols;j++){
		for(i=0;i<rows;i++){
			temp[i][j]=message[k];
			k++;
		}
	}
	k=0;
	//Reading value from col to col
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			if(temp[i][j]=='@'){
				result[k]='\0';
				break;
			}
			result[k]=temp[i][j];
			k++;
		}
	}
	result[k]='\0';
	return 1;
}

