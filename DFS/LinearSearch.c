#include <stdio.h>

void linearSearch(int[],int size, int key); //for only 1 occurence
void linearSearch2(int[],int size, int key); //for all occurences


int main() {

   int arr[15];
   int size;
   int key;
   int i;
   printf("Enter the size of the array(max 15): ");
   scanf("%d",&size);
   printf("Enter the array:\n");
   for(i=0;i<size;++i)
     scanf("%d",&arr[i]);
     
   printf("Enter the element to search: ");
   scanf("%d",&key); 
 
   linearSearch(arr,size,key);
   linearSearch2(arr,size,key);

   

   return 0;
}


void linearSearch(int arr[], int size, int key)
 {
  
    int i=0;
    int flag=0;
    printf("\n----------------------------------------------\nEntered function to print only first occurence of key\n\n");
    for(i=0;i<size;++i)
     {
        if(arr[i]==key)
          {
            printf("%d found at index %d",key,i);
            flag=1;
            break;
          }
     }

     if(!flag)
      {
        printf("Element not found in array!");
      }
 }



void linearSearch2(int arr[], int size, int key)
 {
  
    int i=0;
    int flag=0;
    printf("\n\n----------------------------------------------\nEntered function to print all occurence of key\n\n");
    for(i=0;i<size;++i)
     {
        if(arr[i]==key)
          {
            printf("%d found at index %d\n",key,i);
            flag++;       
          }
     }

     if(!flag)
      {
        printf("Element not found in array!");
      }
    else printf("\nNumber of occurences of %d: %d", key,flag);
 }