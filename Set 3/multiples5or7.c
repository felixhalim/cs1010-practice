#include<stdio.h>

int count_multiples(int x){
	int i,ctr=0;
	for(i = 1;i<=x;i++){
		if(i%5==0||i%7==0)ctr++;
	}
	return ctr;
}

int main(){
	printf("Enter positive integer: ");
	int num;
	scanf("%d", &num);
	int ans = count_multiples(num);
	if(ans>1){
		printf("There are ");
	printf("%d multiples of 5 or 7 in [1,%d].\n",ans,num);
	}else if(ans==0){
		printf("There are no ");
	printf("multiples of 5 or 7 in [1,%d].\n",num);
	}else{
		printf("There is 1 multiple of 5 or 7 in [1,%d].\n",num);
		return 0;
	}

}
