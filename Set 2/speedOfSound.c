#include<stdio.h>
#include<math.h>

float speed_of_sound(float x){
	float ans = 1086*sqrt((5*x+297)/247);
	return ans;
}

int main(){
	float temp;
	printf("Temperature in degree Fahrenheit: ");
	scanf("%f",&temp);
	printf("Speed of sound in air of %.2f degree = %.2f ft/sec\n",temp, speed_of_sound(temp));
	return 0;
}

