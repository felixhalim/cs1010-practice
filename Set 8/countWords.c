#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX_SIZE 51

int word_count(char str[]);

int main(){
	char str[MAX_SIZE];
	printf("Enter a sentence with at most 50 characters:\n");
	fgets(str,MAX_SIZE-1,stdin);
	int len = strlen(str);
	if(str[len-1]=='\n')str[len-1]='\0';
	printf("Sentence = %s\n\n",str);
	printf("Word count = %d\n",word_count(str));

	return 0;
}

int word_count(char str[]){
	int i =0, ptr=0, j;
	int len = strlen(str);
	int count=0;
	for(i=0;i<len;i++){
		if(str[i]==' '||i==len-1){
			for(j=ptr; j<i;j++){
				if(isalpha(str[j])){
					count++;
					break;
				}
			}
			ptr=i+1;
		}
	}
	return count;
}
