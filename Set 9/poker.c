#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define NUMBER_OF_CARDS 5
void read_hand(int []);
int decipher(int);
int isPredicted(int [], int);
void type_and_keycard_ranks(int*p1,int*p2,int*k1,int*k2,int h1[],int h2[]);
int who_wins(int,int,int,int);

int main(void) {
	int hand1[NUMBER_OF_CARDS], hand2[NUMBER_OF_CARDS]; 
	int type1,type2,key1,key2;
	// Read in the hand of the first player
	printf("Enter the hand of player 1:\n");
	read_hand(hand1);
	// Read in the hand of the second player
	printf("Enter the hand of player 2:\n");
	read_hand(hand2);

	type_and_keycard_ranks(&type1,&type2,&key1,&key2,hand1,hand2);
	printf("Player 1 has a hand of type rank %d and key card rank %d.\n",type1,key1);
	printf("Player 2 has a hand of type rank %d and key card rank %d.\n",type2,key2);

	int winner = who_wins(key1,key2,type1,type2);
	if(winner==2){
		printf("Player 2 wins.");
	}else if(winner==1){
		printf("Player 1 wins.");
	}else{
		printf("There is a draw.");
	}
	printf("\n");

	return 0;
}
// Reads an array of integers representing a hand
void read_hand(int hand[]) {
	int i;

	for (i = 0; i < NUMBER_OF_CARDS; i++) {
		scanf("%d", &hand[i]);
	}
}

//Determine the rank of a card
int decipher(int x){
	if(x==1)return 13;
	else return x-1;
}

//Determine if a hand is same as predicted type
int isPredicted(int h[], int predictedType){
	int i,t,pivot,ctr,ans=0,max=-1;
	for(t=0;t<6-predictedType;t++){
		ctr=0;
		pivot = h[t];
		for(i=0;i<NUMBER_OF_CARDS;i++){
			if(h[i]==pivot)ctr++;
		}
		if(ctr==predictedType&&decipher(pivot)>max){
			ans = pivot;
			max = decipher(pivot);
		}
	}
	return ans;
}

// Determine type and key for each player
void type_and_keycard_ranks(int*p1, int*p2, int*k1, int*k2, int h1[], int h2[]){
	int i,card1,card2,flag1=0,flag2=0;
	//Check if card type is 2 or 3 or 4
	for(i=2;i<5;i++){
		card1 = isPredicted(h1,i);
		if(card1){
			*p1 = i;
			*k1 = decipher(card1);
			flag1=1;
		}
		card2 = isPredicted(h2,i);
		if(card2){
			*p2 = i;
			*k2 = decipher(card2);
			flag2=1;
		}
	}
	int max = -1;
	if(flag1==0){
		*p1 = 1;
		for(i=0;i<NUMBER_OF_CARDS;i++){
			if(max<decipher(h1[i])){
				max = decipher(h1[i]);
				*k1 = max;
			}
		}
	}
	max = -1;
	if(flag2==0){
		*p2 = 1;
		for(i=0;i<NUMBER_OF_CARDS;i++){
			if(max<decipher(h2[i])){
				max = decipher(h2[i]);
				*k2 = max;
			}
		}
	}
}

//Determine who wins the game
int who_wins(int key1, int key2, int type1, int type2){
	if(type1>type2)return 1;
	if(type2>type1)return 2;
	if(key1>key2)return 1;
	if(key2>key1)return 2;
	return 0;
}
