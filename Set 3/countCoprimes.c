#include<stdio.h>

int gcd(x,y){
	int i,gcd;
	for(i=1;i<=x && i<=y;++i){
		if(x%i==0&&y%i==0)gcd=i;
	}
	return gcd;
}

int count_coprimes(int x){
	int ctr=0,i,j;
	for(i=2;i<x;i++){
		for(j=i+1;j<=x;j++){
			if(gcd(i,j)==1)ctr++;
		}
	}
	return ctr;
}

int main(){
	int limit;
	printf("Enter limit: ");
	scanf("%d",&limit);
	printf("Answer = %d\n",count_coprimes(limit));
}
