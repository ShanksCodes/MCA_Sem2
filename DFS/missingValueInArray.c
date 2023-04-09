#include <stdio.h>
#include <stdlib.h>

int missingElement(int*,int size); //for only 1 occurence


int main() 
 {

   int size=0;
   int*arr;
   int i=0;
   int missing_element=-1;
   printf("\n----------------------------------------------------------\n");
   printf("\nEnter size of the array: ");
   scanf("%d",&size);
  
   arr= (int*)calloc(size,sizeof(int));

   printf("\nEnter the values between 0 and %d (both inclusive) without repetition:\n",size);
   
   for(i=0;i<size;++i)   
     scanf("%d",&arr[i]);

  missing_element = missingElement(arr,size);
  printf("\nMissing element in the array is: %d", missing_element);
   
  
   printf("\n----------------------------------------------------------\n"); 
   return 0;
 }

                                              
int missingElement(int*arr,int size)    //size=4 -> 0 1 2 3 4 expected => 
 { 
    
   int expected_sum = (size*(size+1))>>1;
   int sum=0;
   int i=0;

   for(i=0;i<size;++i)
    sum+=arr[i];

   return (expected_sum-sum);

 }