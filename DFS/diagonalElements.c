#include <stdio.h>
#include <stdlib.h>

void diagonalElements(int **arr, int rows, int cols); 

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
        for (j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
     }
    

    diagonalElements(arr,rows,cols);

    for(i=0;i<rows;++i)
     free(arr[i]);
    free(arr);   


    printf("\n----------------------------------------------------------\n");
    return 0;
 }


void diagonalElements(int **arr, int rows, int cols)
 {
    int i=0, j=0;

    if (rows!=cols)  
      {
        printf("\nMatrix must be a square matrix");
        return;
      }
   
    
    printf("\n\nDiagonal elements are: ");
    for(i=0;i<rows;++i)
     {
        printf("%d ", arr[i][i]);
     }

     return;
 }


