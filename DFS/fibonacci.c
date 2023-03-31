#include <stdio.h>

void fibonacci(int);

//int factorialR(int num);
     
  int main()
   {
    int num=0;
    int res=1;
    printf("-------------------------------------------------");
    printf("\nEnter the number of terms in fibonacci sequence: ");
    scanf("%d",&num);
    res = fibonacci(num);
    printf("Factorial of %d is %d",num,res);
    printf("-------------------------------------------------");

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

 