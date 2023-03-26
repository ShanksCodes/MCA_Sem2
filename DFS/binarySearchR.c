#include <stdio.h>

int binarySearchR(int[],int size, int key, int start, int end); //for all occurences

int main() {

   int arr[15];
   int size;
   int key;
   int i;
   int pos=-1;
   int start=0,end=0;

   printf("Enter the size of the array(max 15): ");
   scanf("%d",&size);
   printf("Enter the sorted array:\n");
   for(i=0;i<size;++i)
     scanf("%d",&arr[i]);
     
   printf("Enter the element to search: ");
   scanf("%d",&key); 

   end= size-1;
 
  pos = binarySearchR(arr,size,key,start,end);
  if(pos!=-1)
   printf("Element %d found at index %d",key,pos);
  else
   printf("Element not found!"); 


   return 0;
}



int binarySearchR(int arr[], int size, int key, int low, int high)
 {
  
    int m =0;
    
    if(low<=high)
     {
       m = low + (high-low)/2;

       if(arr[m]==key)
         return m;
        

       else if(arr[m]>key)
         return binarySearchR(arr,size,key,low,m-1);
        
       else 
        return binarySearchR(arr,size,key,m+1,high);
     }

     return -1;
 }