#include <stdio.h>

void deletionInArray(int[],int*,int);

int main() {

   int arr[15];
   int size;
   int pos;
   int i;

   printf("Enter the size of the array(max 14): ");
   scanf("%d",&size);
   printf("Enter the array:\n");
   for(i=0;i<size;++i)
     scanf("%d",&arr[i]);
     
   printf("\nEnter the index of element to be deleted from array: ");
   scanf("%d",&pos); 

   deletionInArray(arr,&size,pos);

   printf("\nElement deleted successfully. New array:\n");
   for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }

   
   return 0;
}



void deletionInArray(int arr[], int *size, int pos)
 {
  
     int i=0;

     for(i=pos; i<*(size-1);++i)
      {
        arr[i]=arr[i+1];
      }

     --(*size); 
 }