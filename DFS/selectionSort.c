#include <stdio.h>

void selectionSort(int[],int size); //for only 1 occurence


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
     
   selectionSort(arr,size);

   printf("\nArray sorted successfully. New array:\n");

   for(i=0;i<size;i++)
     printf("%d ",arr[i]);
    
   return 0;
}

void selectionSort(int arr[], int size)
 {
  
    int i=0;
    int min=0;
    int j=0;
    int temp=0;
     
     for(i=0;i<size-1;++i)
      {
        min = i;
        for(j=i+1;j<size;++j)
         {
           if(arr[min]>arr[j])
            {
              min = j;
            }
         }
   
        if(min!=i)
         {
          temp = arr[i];
          arr[i]=arr[min];
          arr[min]=temp;
         }
      }

 }



