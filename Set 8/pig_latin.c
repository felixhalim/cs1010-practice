// pig_latin.c
#include <stdio.h>
#include <string.h>

#define MAX_LEN 80
void shift(char[]);
void mod(char[]);
void convert(char [], char []);
int main(void) {
	char input[MAX_LEN];
	printf("Enter sentence: ");
	fgets(input, MAX_LEN+1,stdin);
	int len = strlen(input);
	if(input[len-1]=='\n')input[len-1]='\0';
	char converted[3*MAX_LEN];
	convert(input,converted);
	printf("\nConverted: %s\n", converted);
	return 0;
}
void shift(char str[]){
	char x = str[0];
	int len = strlen(str);
	int i;
	for(i=0;i<len-1;i++){
		str[i]=str[i+1];
	}
	str[len-1]=x;
}

void mod(char str[]){
	int i=0;
	if(str[i]!='a'&&str[i]!='i'&&str[i]!='u'&&str[i]!='e'&&str[i]!='o'){
		shift(str);
		strcat(str,"ay");
	}else{
		strcat(str,"way");
	}
}
// Convert src into pig-latin in dest
void convert(char src[], char dest[]) {
	char* split = strtok(src," ");
	char splitDup[MAX_LEN];
	while(split!=NULL){
		strcpy(splitDup,split);
		mod(splitDup);
		strcat(dest,splitDup);
		strcat(dest," ");
		split = strtok(NULL," ");
	}
}

