#include<stdio.h>
#include<math.h>

int luhnah(int x){
	int temp, sum=0;
	int i;
	for(i=1;x>0;i++){
		if(i%2==0){
			temp=x%10;
			temp*=2;
			while(temp>0){
				sum+=temp%10;
				temp/=10;
			}
			x/=10;
		}else{
			sum+=x%10;
			x/=10;
		}
	}
	return sum;
}

char* issued(int x){
	int ctr = 0;
	int temp = x;
	while(x>10){
		x/=10;
		ctr++;
	}
	int code=temp/pow(10,ctr-2);
	code/=10;
	if(code>=31&&code<=35)return "East";
	else if(code>=51&&code<=55)return "West";
	return "Central"; 
}

int main(void) {
	int ucardNo;
	printf("Enter uCard Number: ");
	scanf("%d",&ucardNo);
	int checkNum = luhnah(ucardNo);
	printf("The check number is %d\n",checkNum);
	char* branch = issued(ucardNo);
	if(checkNum%7!=0){
		printf("Invalid\n");
	}else{
		printf("Valid\n");
		printf("Issued by %s branch\n",branch);
	}
	return 0;
}

