#include <stdio.h>
#include <stdlib.h>

void foo();

 
int x=5;
int main()
{
  printf("\n----------------------------------------------------------\n");

  foo();
  printf("%d",x);



  printf("\n----------------------------------------------------------\n");
  return 0;
}

void foo()
{
  x=10;
  printf("%d",x);
}


