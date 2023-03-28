#include <stdio.h>
#include <limits.h>

void numLargest(int arr[], int size);

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
     
   numLargest(arr,size);
    
   return 0;
}


void numLargest(int arr[], int size)
 {
    int i=0;
    int maxnum = INT_MIN;

    for(i=0;i<size;++i)
      {
        if(arr[i] > maxnum)
          maxnum = arr[i];
      }

     printf("\n-----------------------------------------\nLargest value in the array is: %d", maxnum);

 }


