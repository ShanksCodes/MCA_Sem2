#include <stdio.h>
#include <limits.h>

void numLargest2(int arr[], int size);

int main() {

   int arr[15];
   int size;
   int key;
   int i;
   int maxval[2]= {0};
   printf("Enter the size of the array(max 15): ");
   scanf("%d",&size);
   printf("Enter the array:\n");
   for(i=0;i<size;++i)
     scanf("%d",&arr[i]);
     
   numLargest2(arr,size);

   

   return 0;
}



void numLargest2(int arr[], int size)
 {
    
    int i=0;
    int maxnum1 = INT_MIN;
    int maxnum2 = INT_MIN;

    for(i=0;i<size;++i)
     {
        if(arr[i]>maxnum1)
         {
            maxnum2=maxnum1;
            maxnum1=arr[i];
         }

        else if(arr[i]>maxnum2 && arr[i]!=maxnum1) 
         {
            maxnum2=arr[i];
         }
    
     }


     printf("\n\n-----------------------------------------------------------\nLargest value in the array is: %d", maxnum1);
     if(maxnum2==INT_MIN)
      printf("\nThere is no 2nd largest element in array");
     else
      printf("\nLargest value in the array is: %d", maxnum2);  

 }
