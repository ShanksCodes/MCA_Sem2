#include <stdio.h>
#include <stdlib.h>

int sumOfElements(int*,int);
int main()
 {
  
   printf("\n----------------------------------------------------------\n\n");
   int*arr=NULL;
   int size=0;
   int sum=0;
   int more=0;
    

   printf("Enter number of elements in array: ");
   scanf("%d",&size);
   arr=(int*) malloc(sizeof(int)*size);
   
   printf("Enter elements of array: ");
   for(int i=0;i<size;i++)
      scanf("%d",&arr[i]);
   
   sum = sumOfElements(arr,size);

   printf("The sum of elements is: %d",sum);

   printf("\n\nEnter number of elements to add to the array: ");
   scanf("%d",&more);

   arr=(int*) realloc(arr,sizeof(int)*(size+more));

   printf("Enter the extra elements for the array: ");
   for(int i=0;i<more;i++)
      scanf("%d",&arr[size+i]);
    size+=more;
   
   sum = sumOfElements(arr,size);
   printf("The sum of elements is: %d",sum);
   
   
   free(arr);
   printf("\n----------------------------------------------------------\n");
   return 0;
 }


 int sumOfElements(int*arr,int size)
 {
   int sum=0;
   for(int i=0;i<size;i++)
      sum+=arr[i];
   
   return sum;
 }