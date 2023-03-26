#include <stdio.h>

int binarySearch(int[],int size, int key); //for all occurences



int main() {

   int arr[15];
   int size;
   int key;
   int i;
   int pos=-1;

   printf("Enter the size of the array(max 15): ");
   scanf("%d",&size);
   printf("Enter the sorted array:\n");
   for(i=0;i<size;++i)
     scanf("%d",&arr[i]);
     
   printf("Enter the element to search: ");
   scanf("%d",&key); 
 
  pos = binarySearch(arr,size,key);
  if(pos!=-1)
   printf("Element %d found at index %d",key,pos);
  else
   printf("Element not found!"); 


   return 0;
}



int binarySearch(int arr[], int size, int key)
 {
  
    int low = 0;
    int high = size-1;
    int m =0;

    while(low<=high)
     {
         
        m= low + (high-low)/2;
    
         if(arr[m]>key)
           {
              high = m-1;
           }
         else if(arr[m]<key)
          {
             low = m+1;
          }  

         else  return m;
     }

     return -1;
 }