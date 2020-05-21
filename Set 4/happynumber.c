#include<stdio.h>
#include<math.h>

int digitsOf(int x){
  int digit=0;
  while(x>0){
    digit++;
    x/=10;
  }
  return digit;
}


int isHappyNumber(int x){
  do{
    int digit = digitsOf(x);
    int newX = 0,i;
    for(i =0;i<digit;i++){
      int temp = x%10;
      newX+=pow(temp,2);
      x/=10;
    }
    x=newX;
  }while(x!=0&&x!=1&&x!=4&&x!=16&&x!=20&&x!=37&&x!=42&&x!=48&&x!=89&&x!=145);
  return x;
}

int computeHappyNumber(int l, int u){
    int count=0;
    int i;
    for(i = l; i<=u;i++){
        if(isHappyNumber(i)==1)count++;
    }
    return count;
}

int main(void)
{
    int lower1, upper1, lower2, upper2, number1, number2;

    printf("Enter first range: ");
    scanf("%d %d",&lower1,&upper1);
    printf("Enter second range: ");
    scanf("%d %d",&lower2,&upper2);
    number1=computeHappyNumber(lower1,upper1);
    number2=computeHappyNumber(lower2,upper2);
    printf("The numbers of happy numbers in the two ranges are: %d %d\n", number1, number2);
    if(number1>number2)
    {
        printf("There are more happy numbers in the first range.\n");
    }
    else if(number1==number2)
    {
        printf("The numbers of happy numbers in both ranges are the same.\n");
    }
    else
    {
        printf("There are more happy numbers in the second range.\n");
    }

    return 0;
}
