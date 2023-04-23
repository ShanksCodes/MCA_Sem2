#include <stdio.h>
#include <stdlib.h>

void duplicateElementDel(int*,int *size);
void bubbleSort(int[],int);  
void deletionInArray(int[],int*,int);


int main() 
 {

   int size=0;
   int*arr;
   int i=0;
   printf("\n----------------------------------------------------------\n");
   printf("\nEnter size of the array: ");
   scanf("%d",&size);
  
   arr= (int*)calloc(size,sizeof(int));

   if(arr==NULL)
    {
      printf("\nMemory allocation failed.\n");
      exit(1);
    }


   printf("\nEnter elements of array:\n",size);
   
   for(i=0;i<size;++i)   
     scanf("%d",&arr[i]);

   duplicateElementDel(arr,&size);

   printf("\nArray after deleting duplicates: ");
   
   for(i=0; i<size; ++i)   
     printf("%d ",arr[i]);
   
   free(arr);
   printf("\n----------------------------------------------------------\n");
   return 0;
 }



// sample input size=12 =>2 4 2 2 -2 2 3 4 7 9 9 9                                              
void duplicateElementDel(int*arr,int *size)
 {

    bubbleSort(arr,*size);   
    int i=0,j=0;

 

    for(i=0;i<*size-1;++i)
     { 
        if(arr[i]!=arr[i+1])
          continue;


        else 
         {
            deletionInArray(arr,size,i);   //-2 2 2 2 2 3 4 4 7 9 9 9
            --i; 
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


void deletionInArray(int arr[], int *size, int pos)
 {
  
     int i=0;

     for(i=pos; i<(*size-1);++i)
      {
        arr[i]=arr[i+1];
      }

     --(*size); 

 }


 