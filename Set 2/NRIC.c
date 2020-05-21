#include<stdio.h>
#include<math.h>

int modify(int x){
	int ans=0;
	int i=0;
	int corrWeight[]={2,3,4,5,6,7,2};
	while(x>0){
		ans+=(x%10*corrWeight[i]);
		i++;
		x/=10;
	}
	ans=11-ans%11;
	return ans;
}

char generateCode(int x){
	char ans;
	switch(x){
		case 1:
			ans='A';
			break;
		case 2:
			ans='B';
			break;
		case 3:
			ans='C';
			break;
		case 4:
			ans='D';
			break;
		case 5:
			ans='E';
			break;
		case 6:
			ans='F';
			break;
		case 7:
			ans='G';
			break;
		case 8:
			ans='H';
			break;
		case 9:
			ans='I';
			break;
		case 10:
			ans='Z';
			break;
		case 11:
			ans='J';
			break;
	}
	return ans;
}

int main(){
	int nric;
	printf("Enter 7-digit NRIC number: ");
	scanf("%d",&nric);
	printf("Check code is %c\n", generateCode(modify(nric)));
}
