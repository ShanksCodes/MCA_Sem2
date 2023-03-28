#include <stdio.h>
#include <stdlib.h>

//void bubbleSort(int[],int size); //for only 1 occurence
void testing();

int main() {

   int arr[15];
   int size;
   int key;
   int i;
   printf("\n----------------------------------------------------------------------------\n");

  // printf("Enter the size of the array(max 15): ");
  // scanf("%d",&size);
  // printf("Enter the array:\n");
  // for(i=0;i<size;++i)
   //  scanf("%d",&arr[i]);
     
   testing();

  /* printf("\nArray sorted successfully. New array:\n");

   for(i=0;i<size;i++)
     printf("%d ",arr[i]);*/
    
   return 0;
}


void testing()
 {
  
   int arr[10];
   int i=0;
   int*output_arr;
       output_arr = (int*)calloc(5,sizeof(int));

   //memset(arr,0,5*sizeof(int));
   for(i=0;i<5;++i)
   printf("%d",output_arr[i]);


 }



