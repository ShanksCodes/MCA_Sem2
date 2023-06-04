#include <stdio.h>
#include <stdlib.h>

void foo();

struct Node
 {
  int data;
  struct Node*next;
 }
 
int x=5;
int main()
{
  printf("\n----------------------------------------------------------\n");

 struct Node*root=NULL;
 free(root);



  printf("\n----------------------------------------------------------\n");
  return 0;
}

void foo()
{
  x=10;
  printf("%d",x);
}


