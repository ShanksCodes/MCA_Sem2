#include <stdio.h>
#include <stdlib.h>

struct sample{
   int data;
  char name[20];
};


void foo2(struct sample*);

 

int main()
{
  printf("\n----------------------------------------------------------\n");


 struct sample*s= (struct  sample*) malloc(5*sizeof(struct sample));


 

 printf("%snamee\n",s[0].name);

 foo2(s);
 printf("%d\n",s[0].data);




  printf("\n----------------------------------------------------------\n");
  return 0;
}


void foo2(struct sample*s)
 {
   s[0].data=30;
   printf("%d\n",s[0].data);
 }
