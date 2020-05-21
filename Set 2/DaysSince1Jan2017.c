#include<stdio.h>

int computeDays(int day, int month){
	int ans=day;
	switch(month){
		case 12:
			ans+=30;
		case 11:
			ans+=31;
		case 10:
			ans+=30;
		case 9:
			ans+=31;
		case 8:
			ans+=31;
		case 7:
			ans+=30;
		case 6:
			ans+=31;
		case 5:
			ans+=30;
		case 4:
			ans+=31;
		case 3:
			ans+=28;
		case 2:
			ans+=31;
		case 1:
			break;
	}
	return ans;
}

int main(){
	int day, month;
	printf("Enter day and month: ");
	scanf("%d %d",&day,&month);
	printf("Day %d of month %d is the %dth day of 2017.\n",day, month, computeDays(day,month));

}
