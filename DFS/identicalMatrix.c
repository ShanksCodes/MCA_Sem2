#include <stdio.h>
#include <stdlib.h>

int checkIdentical(int **arr, int**arr2,int rows, int cols,int rows2, int cols2); 

int main() 
 {
    int rows=0, cols=0,i=0,j=0;
    int rows2=0,cols2=0;
    
    printf("\n----------------------------------------------------------\n");
    printf("Enter the number of rows and columns for matrix 1: ");
    scanf("%d%d", &rows, &cols);

    printf("Enter the number of rows and columns for matrix 2: ");
    scanf("%d%d", &rows2, &cols2);


    int **arr = (int **) malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) 
        arr[i] = (int *) malloc(cols * sizeof(int));

    int **arr2 = (int **) malloc(rows2 * sizeof(int *));
    for (i = 0; i < rows2; i++) 
        arr2[i] = (int *) malloc(cols2 * sizeof(int));

    printf("\nEnter the elements of matrix 1:\n");
    for (i = 0; i < rows; i++) 
     {
        for (j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
     }
    

    printf("\nEnter the elements of matrix 2:\n");
    for (i = 0; i < rows2; i++) 
     {
        for (j = 0; j < cols2; j++) {
            scanf("%d", &arr2[i][j]);
        }
     }
    

    if(checkIdentical(arr,arr2,rows,cols,rows2,cols2)==1)
        printf("\nMatrices are identical");
    else
        printf("\nMatrices are not identical"); 

   for(i=0;i<rows;++i)
     free(arr[i]);
    free(arr);

   for(i=0;i<rows2;++i)
     free(arr2[i]);
    free(arr2);

    printf("\n----------------------------------------------------------\n");
    return 0;
 }


int checkIdentical(int **arr,int **arr2, int rows, int cols, int rows2, int cols2)
 {
    int i=0, j=0;

    if (rows!=rows2 || cols!=cols2)  
        return -1;
   

    for (i = 0; i < rows; i++) 
     {
        for (j = 0; j < cols; j++) 
         {
            if(arr[i][j]!=arr2[i][j])
             {
                return -1;
             }
         }
     }

     return 1;
 }


