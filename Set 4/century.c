#include<stdio.h>
#include<math.h>

int printCentury(int x){
	int ans = ((x+100)/100);
	return ans;
}

char* printOrdinal(int x){
	char* temp;
	if(x%10==1&&(x/10)%10!=1){
		temp="st";
	}else if(x%10==2&&(x/10)%10!=1){
		temp="nd";
	}else if(x%10==3&&(x/10)%10!=1){
		temp="rd";
	}else{
		temp="th";
	}
	return temp;
}

int main(){
	printf("Enter year: ");
	int input;
	scanf("%d",&input);
	int ans = printCentury(input);
	char* ordinal = printOrdinal(ans);
	printf("The year %d falls in the %d%s century.\n",input,ans,ordinal);
	
	return 0;
}
