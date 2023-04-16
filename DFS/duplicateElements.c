#include <stdio.h>
#include <stdlib.h>

int* duplicateElement(int*,int size);
void bubbleSort(int[],int);  


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

   if(arr==NULL)
    {
      printf("\nMemory allocation failed.\n");
      exit(1);
    }


   printf("\nEnter elements of array:\n",size);
   
   for(i=0;i<size;++i)   
     scanf("%d",&arr[i]);

   dup_arr = duplicateElement(arr,size);

   printf("\nDuplicate elements in array are: ");
   
   for(i=1;i<=dup_arr[0];++i)   
     printf("%d ",dup_arr[i]);
   
   free(arr);
   free(dup_arr);
   printf("\n----------------------------------------------------------\n");
   return 0;
 }



// sample input size=12 =>2 4 2 2 -2 2 3 4 7 9 9 9                                              
int* duplicateElement(int*arr,int size)
 {
    int*darr = (int*)calloc(size+1,sizeof(int));
    
    if(darr==NULL)
     {
       printf("\nMemory allocation failed.\n");
       exit(1);
     }

    bubbleSort(arr,size);

    int i=0,j=0;
    int k=1;
    darr[0]=0;  //acts as counter for duplicates

    int flag=0;

    for(i=0;i<size-1;++i)
     { 
        if(arr[i]!=arr[i+1])
          {
            if(flag==0)
             continue;
            else
             flag=0;
          } 


        else if(arr[i]==arr[i+1])
          {
            if(flag==0)
             {
               darr[++darr[0]]=arr[i];
               flag=1;
             } 

            else
             continue;
          }
  
     }

   darr = realloc(darr,(darr[0]+1)*sizeof(int));  //reallocate array to trim its size   

   return darr;

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





 