#include <stdio.h>

int factorial(int);

int factorialR(int num);
     
  int main()
   {
    int num=0;
    int res=1;
    printf("-------------------------------------------------");
    printf("\nEnter number to find its factorial: ");
    scanf("%d",&num);
    res = factorial(num);
    printf("Factorial of %d(without recursion) is %d",num,res);
    res = factorialR(num);
    printf("\nFactorial of %d(with recursion) is %d",num,res);

    printf("\n-------------------------------------------------");

    return 0;
   }

int factorial(int num)
 {
    int i=2;
    int res=1;
    while(i<=num)
     {
       res*=i;
       i++;
     }

     return res;
 }

 int factorialR(int num)
  {
    if (num==1)
     return 1;
    else
     return num*factorialR(num-1);
  }

 