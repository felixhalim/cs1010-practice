/**
 * CS1010 AY2017/8 Semester 1 Lab4 Ex3
 * frogs.c
 * PROGRAM TO SIMULATE FROG JUMPING
 * (A WAY FOR THE FROGS TO CROSS THE BRIDGE)
 * FELIX HALIM
 * T04
 */
#include <stdio.h>
int jump(int, int, int[], int, int*);
void printBridge(int, int[]);
int checkGameState(int, int[]);
int isWin(int, int[]);
int main(void) {
	int bridge[1000];
	int i;
	int lengthOfBridge;
	int position;
	int numMoves = 0;
	int *p_move = &numMoves;
	printf("Please enter the length of the bridge: ");
	scanf("%d", &lengthOfBridge);
	for (i=0; i<lengthOfBridge; i++) {
		int frogType;
		printf("Please insert frogs at position %d: ", i);
		scanf("%d", &frogType);
		bridge[i] = frogType;
	}
	printf("Input completed\n");
	printBridge(lengthOfBridge, bridge);
	printf("Please start moving the frogs\n");
	
	while(checkGameState(lengthOfBridge,bridge)){
		printf("Move the frog at position: ");
		scanf("%d",&position);
		if(jump(position,lengthOfBridge,bridge,0,p_move)==0){
			printf("Invalid move!\n");
		}else{
			printBridge(lengthOfBridge, bridge);
		}
	}
	if(isWin(lengthOfBridge, bridge)){
		printf("Congratulations! The frogs took %d jumps to cross the bridge!",numMoves);
	}else{
		printf("Oh no! It seems like the two clans of frog are stuck!");
	}
	printf("\n");
	return 0;
}

// Function to determine if a frog able to jump 
// to the empty space directly in front of it
// OR jump over a frog to the empty space behind the latter
// then perform the jump if int check = 0 then return 1
// or return 1 ONLY if check = 1
// or return 0 if NOT ABLE TO JUMP
int jump(int pos ,int size, int bridge[],int check, int *ctr){
	int ctrTemp=*ctr;
	if(bridge[pos]<0){
		if(pos-1>=0 && bridge[pos-1]==0){
			if(check==1)return 1;
			bridge[pos-1]=bridge[pos];
			bridge[pos]=0;
			ctrTemp++;
			*ctr=ctrTemp;
			return 1;
		}else{
			if(pos-2>=0 && bridge[pos-2]==0){
				if(check==1)return 1;
				bridge[pos-2]=bridge[pos];
				bridge[pos]=0;
				ctrTemp++;
				*ctr=ctrTemp;
				return 1;
			}
		}
	}else if(bridge[pos]>0){
		if(pos+1<size && bridge[pos+1]==0){
			if(check==1)return 1;
			bridge[pos+1]=bridge[pos];
			bridge[pos]=0;
			ctrTemp++;
			*ctr=ctrTemp;
			return 1;
		}else{
			if(pos+2<size&& bridge[pos+2]==0){
				if(check==1)return 1;
				bridge[pos+2]=bridge[pos];
				bridge[pos]=0;
				ctrTemp++;
				*ctr=ctrTemp;
				return 1;
			}
		}
	}
	return 0;
}

/**
 * Prints out the current state on the bridge
 * @param size (int) represents the size of bridge
 * @param bridge[] contains the current state of the bridge
 **/
void printBridge(int size, int bridge[]) {
	int i;
	printf("Position: ");
	for (i=0; i<size; i++) {
		printf("%2d ", i);
	}
	printf("\n");
	printf("Bridge:   ");
	for (i=0; i<size; i++) {
		printf("%2d ", bridge[i]);
	}
	printf("\n");
}
// Check if there is still possible move then return 1
// if not then return 0
int checkGameState(int size, int bridge[]){
	int nothing=888,i;
	int *p_nothing=&nothing;
	if(isWin(size,bridge))return 0;
	for(i=0;i<size;i++){
		if(jump(i,size,bridge,1,p_nothing)==1)return 1;
	}
	return 0;
}

// Check if player win the game then return 1
// if not then return 0
int isWin(int size, int bridge[]){
	int i,flag=0,counter=0;
	for(i=0;i<size;i++){
		if(bridge[i]==-1&&flag==0)counter++;
		else if (bridge[i]==0){
			counter++;
			flag=1;
		}
		else if (bridge[i]==1&&flag==1)counter++;
	}
	if(counter==size)return 1;
	return 0;
}

