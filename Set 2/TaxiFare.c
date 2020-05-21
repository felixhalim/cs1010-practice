#include<stdio.h>
#include<math.h>

float computeFare(int dayType, int boardTime, int distance){
	float totalFare=3.4;
	if(distance>10200){
		distance-=10200;
		float nextOne=ceil((float)(distance)/350)*0.22;
		float nextTwo=23*0.22;
		totalFare+=nextOne+nextTwo;
	}else{
		if(distance>1000){
			totalFare+=ceil((float)(distance-1000)/400)*0.22;
		}
	}
	//multiplier
	if(dayType==0){
		if(boardTime<360){
			totalFare+=totalFare*0.50;
		}else{
			if(boardTime<360+210){
			}else{
				if(boardTime<1080){}
				else{totalFare+=totalFare*0.25;}
			}
		}
	}else{
		if(boardTime<360){
			totalFare+=totalFare*0.50;
		}else{
			if(boardTime<360+210){
				totalFare+=totalFare*0.25;
			}else{
				if(boardTime<1080){}
				else{totalFare+=totalFare*0.25;}	
			}
		}
	}
	return totalFare;
}

int main(){
	int dayType, boardHour, boardMin, distance;
	printf("Day type: ");
	scanf("%d",&dayType);
	printf("Boarding hour and minute: ");
	scanf("%d %d", &boardHour, &boardMin);
	printf("Distance: ");
	scanf("%d",& distance);
	int boardTime = boardMin+boardHour*60;
	printf("Boarding time is %d minutes\n",boardTime);
	float fare = computeFare(dayType, boardTime, distance);
	printf("Total taxi fare is $%.2f\n",fare);

	return 0;
}
