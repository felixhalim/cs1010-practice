/**
 * CS1010 AY2019/20 Semester 1 Lab1 Ex1
 * invest.c
 * This program calculates the final amount given principal amount,
 * interest rate, and number of years, based on compound interest.
 * FELIX HALIM
 * T04
 */

int main(void) {
	int principal,rate,numYears;

	printf("Enter principal amount: ");
	scanf("%d",&principal);

	printf("Enter interest rate   : ");
	scanf("%d",&rate);

	printf("Enter number of years : ");
	scanf("%d",&numYears);

	float amountMoney = ((float)principal*(1-pow(((float)rate/100),numYears+1)))/(1-(float)rate/100); 
	printf("Amount = $%.2f\n",amountMoney);

	return 0;
}

