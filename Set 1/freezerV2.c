#include<stdio.h>
#include<math.h>
int main(){
	int hour, min;
	printf("Enter hours and minutes since power failure: ");
	scanf("%d %d", &hour, &min);
	double time=(double)min/60;
	time+=hour;
	double temp=4*pow(time,10)/(pow(time,9)+2)-20;
	printf("Temperature in freezer = %.2f\n",temp);
	return 0;
}
