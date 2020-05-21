// rot.c
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 80
void encrypt(char [], char []);
void decrypt(char [], char []);
int main(void) {
	int status;
	printf("Enter 1 for encryption, 2 for decryption: ");
	scanf("%d",&status);
	char dump;
	scanf("%c",&dump);
	char str[MAX_LENGTH];
	char ans[MAX_LENGTH];
	printf("Enter message: ");
	fgets(str,MAX_LENGTH+1,stdin);
	int len = strlen(str);
	if(str[len-1]=='\n')str[len-1]='\0';
	if(status==1){
		encrypt(str,ans);
		printf("Encrypted message: %s\n",ans);
	}else{
		decrypt(str,ans);
		printf("Decrypted message: %s\n",ans);
	}

	return 0;
}
// Encrypt a message based on transpose-13 algorithm
void encrypt(char message[], char result[]){
	int len = strlen(message);
	int i;
	for(i=0;i<len;i++){
		if(message[i]>='A'&&message[i]<='Z')
			result[i]=(message[i]-'A'+13)%26+'A';
		else
			result[i]=(message[i]-'a'+13)%26+'a';
	}
	result[len]='\0';
}
// Decrypt a message based on transpose-13 algorithm
void decrypt(char message[], char result[]){
	int len = strlen(message);
	int i;
	for(i=0;i<len;i++){
		if(message[i]>='A'&&message[i]<='Z')
			result[i]=(message[i]-'A'+13)%26+'A';
		else
			result[i]=(message[i]-'a'+13)%26+'a';
	}
	result[len]='\0';
}
