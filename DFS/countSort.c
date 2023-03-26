#include <stdio.h>

void countSort(int[],int size); //for only 1 occurence


int main() {

   int arr[15];
   int size;
   int key;
   int i;
   printf("\n----------------------------------------------------------------------------\n");

   printf("Enter the size of the array(max 15): ");
   scanf("%d",&size);
   printf("Enter the array:\n");
   for(i=0;i<size;++i)
     scanf("%d",&arr[i]);
     
   countSort(arr,size);

   printf("\nArray sorted successfully. New array:\n");

   for(i=0;i<size;i++)
     printf("%d ",arr[i]);
    
   return 0;
}

void countSort(int arr[], int size)
 {
  
    int i=0;
    int j=0; //
    int key=0;
     
     for(i=1;i<size;++i)
      {
         key=arr[i];
         j=i-1;

         while(j>=0 && arr[j]>key)
          {
            arr[j+1] = arr[j];
            --j;
          }

         arr[j+1]=key; 

      }

 }



