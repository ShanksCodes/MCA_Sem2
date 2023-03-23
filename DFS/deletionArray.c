#include <stdio.h>

void insertInArray(int[],int&,int,int);


int main() {

   int arr[15];
   int size;
   int el;
   int pos;
   int i;

   printf("Enter the size of the array(max 14): ");
   scanf("%d",&size);
   printf("Enter the array:\n");
   for(i=0;i<size;++i)
     scanf("%d",&arr[i]);
     
   printf("Enter the element to insert: ");
   scanf("%d",&el); 

   printf("Enter the index to insert element at: ");
   scanf("%d",&pos); 
 
   insertInArray(arr,size,el,pos);

   printf("\nElement inserted successfully. New array:\n");
   for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }

   

   return 0;
}


void insertInArray(int arr[], int &size, int el, int pos)
 {
  
    int i=0;

    for(i=size; i>pos;--i)
     {
        arr[i] = arr[i-1];
     }

    arr[pos]= el;
    size++; 
 }