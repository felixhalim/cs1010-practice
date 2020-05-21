#include<stdio.h>

int contain(int i,int m){
	while(i>0){
		int temp = i%10;
		if(temp==m)return 1;
		i/=10;
	}
	return 0;
}

int computeWinners(int f, int m, int n){
	int i,ctr=0;
	for(i=1;i<=n;i++){
		if(i%f==0&&contain(i,m)){
			ctr++;
		}
	}
	return ctr;
}

int main(void) {   
	int factor, mustHave, n;   
	printf("Enter factor-digit: ");
	scanf("%d",&factor);
	printf("Enter must-have-digit: ");
	scanf("%d",&mustHave);
	printf("Enter number of participants: "); 
	scanf("%d",&n);
	int ans = computeWinners(factor,mustHave,n);
	printf("Number of winners: %d\n",ans);
	return 0; 
}
