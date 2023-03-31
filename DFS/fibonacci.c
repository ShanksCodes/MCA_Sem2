#include <stdio.h>

void fibonacci(int);

void fibonacciR(int num);
     
  int main()
   {
    int num=0;
    int res=1;
    printf("\n-------------------------------------------------------");
    printf("\nEnter the number of terms in fibonacci sequence: ");
    scanf("%d",&num);
    printf("\nFibonacci sequence upto %d terms without recursion:",num);
    fibonacci(num); 
    printf("\n\nFibonacci sequence upto %d terms with recursion:",num);
    printf("\n%d, %d",0,1); 
    fibonacciR(num);
    printf("\n-------------------------------------------------------");


    return 0;
   }

void fibonacci(int num)
 {
   int i=0;
   int a=0;
   int b=1;
   int c=0;
   printf("\n%d, %d",a,b);  //0 1 1 2 3 5 8 13

   for(i=0;i<num-2;++i)
    {
      c=a+b;
      printf(", %d",c);
      a=b;
      b=c;
    }

  }

 
 void fibonacciR(int num)
  {
    static int a=0,b=1,c=0;

    if(num>2)
     {
      c=a+b;
      a=b;
      b=c;
      printf(", %d",c);
      fibonacciR(num-1);

     }
  }