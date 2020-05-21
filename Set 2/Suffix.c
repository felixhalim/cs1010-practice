#include<stdio.h>

void printSuffix(int x){
	int ans;
	const char *suffix[4]={"st","nd","rd","th"};
	if(x%10==1&&x/10%10!=1){
		ans=0;
	}else if(x%10==2&&x/10%10!=1){
		ans=1;
	}else if(x%10==3&&x/10%10!=1){
		ans=2;
	}else{
		ans=3;
	}
	printf("%d%s\n",x,suffix[ans]);
}

int main(){
	int value;
	printf("Enter value: ");
	scanf("%d", &value);
	printSuffix(value);
	
	return 0;
}
