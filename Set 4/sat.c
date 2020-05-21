#include<stdio.h>

int compute_percentile(int x){
	if(x>=2200)return 99;
	else if(x>=2000)return 95;
	else if(x>=1500)return 50;
	return 10;
}

double compute_iqscore(int x, int y){
	double iq = (0.095*(double)y)+(0.003*(double)x)+50.241; 
	return iq;
}

int main(void) {
	int verbal, maths, writing ; 
	printf("Enter scores: ");
	scanf("%d %d %d",&verbal,&maths,&writing);
	int percentile = compute_percentile(verbal+maths+writing);
	printf("The SAT score is in the %d percentile.\n",percentile);
	double iq = compute_iqscore(verbal,maths);
	printf("The IQ score is %.2lf\n",iq);
	if((verbal>600&&maths>600&&writing>600)||iq>=120)printf("Wow, this is amazing!\n");
	return 0;
}
