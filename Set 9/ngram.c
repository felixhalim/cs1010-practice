// CS1010 AY2014/5 Semester 1
// PE2 Ex1: ngram.c
// Name: FELIX HALIM 
// Matriculation number: A0200664N 
// plab-id: P05
// Discussion group: T04 
// Description: 
// Program to compute the frequency and determine the 
// most frequent unigram or most frequent bigram
// then output the result and the frequency
// Precond :
// input text is all lowercase
// "x y" -> "x " and " y" is not a bigram
// "x" is unigram, " " is not a unigram, "y" is a unigram
// in order to be considered bigram element n
// and element n+1 must not be a space
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 101

int mostFrequentUnigram(char [], char[]);
int mostFrequentBigram(char [], char[]);

int main(void) {
	char text[MAX_SIZE], result[3];
	int option, unigramFreq, bigramFreq;

	printf("Enter text: ");
	fgets(text,MAX_SIZE,stdin);
	int len = strlen(text);
	if(text[len-1]=='\n')
		text[len-1]='\0';
	printf("Enter option: ");
	scanf("%d",&option);
	if(option==1){
		unigramFreq = mostFrequentUnigram(text,result);
		printf("Most frequent unigram: %s\n", result);
		printf("Frequency: %d\n", unigramFreq);
	}else if(option==2){
		bigramFreq = mostFrequentBigram(text,result);
		printf("Most frequent bigram: %s\n", result);
		printf("Frequency: %d\n", bigramFreq);
	}
	return 0;
}

//Function to determine the most frequent unigram
//and output the frequency
int mostFrequentUnigram(char text[MAX_SIZE], char result[3]){
	int i,j,ctr;
	int max=-1;
	char unigram;
	int len = strlen(text);

	for(i=0;i<len;i++){
		ctr=0;
		char pivot = text[i];
		for(j=i;j<len&&pivot!=' ';j++){
			if(text[j]==pivot)ctr++;
		}
		if(ctr>max){
			max = ctr;
			unigram = pivot;
		}else if(ctr==max&&pivot<unigram){
			max = ctr;
			unigram = pivot;
		}
	}
	result[0]=unigram;
	result[1]='\0';
	return max;
}

//Function to determine the most frequent bigram
//and output the frequency
int mostFrequentBigram(char text[MAX_SIZE], char result[3]){
	char pivot[3];
	int i;
	int len = strlen(text);
	int ctr,max=-1;
	char* find;
	for(i=0;i<len-1;i++){
		ctr=0;
		if(text[i]!=' '&&text[i+1]!=' '){
			pivot[0]=text[i];
			pivot[1]=text[i+1];
			pivot[2]='\0';
		}
		find = strstr(text,pivot);
		
		while(find!=NULL){
			ctr++;
			find = strstr(find+1,pivot);
		}

		if(ctr>max){
			max=ctr;
			strcpy(result,pivot);
		}else if(ctr==max && pivot[0] < result[0]){
			max=ctr;
			strcpy(result,pivot);
		}else if (ctr==max && pivot[0]==result[0]&&pivot[1]<result[1]){
			max=ctr;
			strcpy(result,pivot);
		}
	}
	return max;
}
