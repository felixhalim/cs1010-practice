#include <stdio.h>
#include <math.h>

int main(void) {
	int a, *a_ptr;
	float b, *b_ptr;
	a_ptr = &a;
	b_ptr =&b;
	printf("Enter an integer: ");
	scanf("%d", &a);
	printf("Enter a real number: ");
	scanf("%f", &b);
	
	printf("Values entered are %d and %.2f\n",*a_ptr,*b_ptr);
	while(*a_ptr<pow(*b_ptr,2)){
		*a_ptr *= *b_ptr;
	}
	printf("Final value of a = %d\n",*a_ptr);

	return 0; 
}
