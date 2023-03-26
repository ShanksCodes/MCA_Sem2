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
    int*count_arr;
    int*output_arr;
     
    int max=arr[0];
    for(i=1; i<size; ++i)
     {
      if(arr[i]>max)
       max=arr[i];
     }
     
    count_arr = (int*)malloc((max+1)*sizeof(int)); 
    output_arr = (int*)malloc(size*sizeof(int));
    memset(count_arr, 0, (max+1)*sizeof(int));
    memset(count_arr, 0, (size)*sizeof(int));
  
    for(i=0;i<size;++i)
     {
      count_arr[arr[i]]++;
     }
   
    for(i=1;i<=max;++i)
     {
      count_arr[i]+=count_arr[i-1];
     }    

    for(i=size-1; i>=0; --i)
     { 
       output_arr[count_arr[arr[i]]-1] = arr[i];
       count_arr[arr[i]]--;
       
     }
     

    for(i=0;i<size;++i)
      {
        arr[i] = output_arr[i];
       
      }
   for(i=0;i<size;i++)
     printf("%d ",arr[i]); 

   free(count_arr);
   free(output_arr);

 }



