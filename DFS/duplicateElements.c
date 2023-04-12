#include <stdio.h>
#include <stdlib.h>

int* duplicateElement(int*,int size);


int main() 
 {

   int size=0;
   int*arr;
   int*dup_arr;
   int i=0;
   printf("\n----------------------------------------------------------\n");
   printf("\nEnter size of the array: ");
   scanf("%d",&size);
  
   arr= (int*)calloc(size,sizeof(int));

   printf("\nEnter elements of array:\n",size);
   
   for(i=0;i<size;++i)   
     scanf("%d",&arr[i]);

   dup_arr = duplicateElement(arr,size);
   printf("\nDuplicate elements in array are: ")
   
   for(i=1;i<=dup_arr[0];++i)   
     printf("%d ",dup_arr[i]);
   
  
   printf("\n----------------------------------------------------------\n"); 
   return 0;
 }

                                              
int* duplicateElement(int*arr,int size)
 {
    int*darr = (int*)calloc(size+1,sizeof(int));
    bubbleSort(arr,size);
    int i=0,j=0;

    int(i=0;i<size-1;++i)
     {
        while(arr[j++]==arr[i])
         {
            
         }
     }



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



