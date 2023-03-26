#include <stdio.h>

void bubbleSort(int[],int size); //for only 1 occurence


int main() {

   int arr[15];
   int size;
   int key;
   int i;

   printf("Enter the size of the array(max 15): ");
   scanf("%d",&size);
   printf("Enter the array:\n");
   for(i=0;i<size;++i)
     scanf("%d",&arr[i]);
     
   bubbleSort(arr,size);

   printf("\nElement inserted successfully. New array:\n");

   for(i=0;i<size;i++)
     printf("%d ",arr[i]);
    
   return 0;
}


void bubbleSort(int arr[], int size)
 {
  
    int i=0;
    int flag=0;
    int j=0
     

 }



