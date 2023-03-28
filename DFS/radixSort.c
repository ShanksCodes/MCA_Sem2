#include <stdio.h>
#include <stdlib.h>

void radixSort(int[],int);
void countSort(int[],int,int); 


int main() {

   int*arr;
   int size;
   int key;
   int i;
   printf("\n----------------------------------------------------------------------------\n");

   printf("Enter the size of the array(max 15): ");
   scanf("%d",&size);
   arr = (int*)calloc(size,sizeof(int));

   printf("Enter the array:\n");
   for(i=0;i<size;++i)
     scanf("%d",&arr[i]);
     
   radixSort(arr,size);

   printf("\nArray sorted successfully. New array:\n");

   for(i=0;i<size;i++)
     printf("%d ",arr[i]);
    
   return 0;
}

void radixSort(int arr[], int size)
 {
  
    int i=0;
    int pf=1;
   
    int max=arr[0];
    for(i=1; i<size; ++i)
     {
      if(arr[i]>max)
       max=arr[i];
     }
       
   
    for(pf=1;max/pf>0;pf*=10)
     {
        countSort(arr,size,pf);
     }
     

 }



 ///////count sort//////
void countSort(int arr[], int size, int pf)
 {
  
    int i=0;
    int j=0; 
    int key=0;
    int count_arr[10]={0};
    int*output_arr=(int*)calloc(size,sizeof(int));;


    //frequency array 
    for(i=0;i<size;++i)
       count_arr[(arr[i]/pf)%10]++;    //pf will sequentially find leftover value and mod will 
                                      //find sequential corrosponding unit, tens, zeros place etc  
      
    
    //converting to cumulative frequency array
    for(i=1;i<10;++i)
     {
      count_arr[i]+=count_arr[i-1];
     }    

    //sorting to output_arr
    for(i=size-1; i>=0; --i)   //can also start from 0 to <size, but that will not be stable
     { 
       output_arr[count_arr[(arr[i]/pf)%10]-1] = arr[i];
       count_arr[(arr[i]/pf)%10]--;      
     }


    for(i=0;i<size;++i)
      {
        arr[i] = output_arr[i];
       
      }

   free(output_arr);

 }




