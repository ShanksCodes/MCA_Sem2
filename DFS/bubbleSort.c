#include <stdio.h>

void bubbleSort(int[],int size); //for only 1 occurence


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
     
   bubbleSort(arr,size);

   printf("\nArray sorted successfully. New array:\n");

   for(i=0;i<size;i++)
     printf("%d ",arr[i]);
    
   return 0;
}


void bubbleSort(int arr[], int size)
 {
  
    int i=0;
    int flag=0;
    int j=0;
    int temp=0;
     
     for(i=0;i<size-1;++i)
      {
        for(j=0;j<size-1-i;++j)
         {
           if(arr[j]>arr[j+1])
            {
              temp = arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=temp;
              flag=1;
            }
         }

         if(!flag)
           break;
         flag=0;
      }

 }



