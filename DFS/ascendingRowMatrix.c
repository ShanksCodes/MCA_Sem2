#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int[],int size); 
void ascendRow(int **arr, int rows, int cols); 
void printArray(int **arr, int rows, int cols);

int main() 
 {
    int rows=0, cols=0,i=0,j=0;
    
    printf("\n----------------------------------------------------------\n");
    printf("Enter the number of rows and columns for the matrix: ");
    scanf("%d%d", &rows, &cols);


    int **arr = (int **) malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) 
        arr[i] = (int *) malloc(cols * sizeof(int));

    printf("\nEnter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) 
     {
        for (j = 0; j < cols; j++) 
         {
            scanf("%d", &arr[i][j]);
         }
     }
    

    ascendRow(arr,rows,cols);
    printf("\nRow sorted matrix:\n");
    printArray(arr,rows,cols);

    for(i=0;i<rows;++i)
     free(arr[i]);
    free(arr);   


    printf("\n----------------------------------------------------------\n");
    return 0;
 }


void ascendRow(int **arr, int rows, int cols)
 {
    int i=0, j=0;
    int sum=0;
       
    for (i = 0; i < rows; i++) 
     {
       bubbleSort(arr[i],cols);
     }


     return;
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

 void printArray(int **arr, int rows, int cols)
   {
     int i=0,j=0;

     for(i=0;i<rows;i++)
      {
        for(j=0;j<cols;++j)
         {
            printf("%d ",arr[i][j]);
         }

         printf("\n");
      }
   }