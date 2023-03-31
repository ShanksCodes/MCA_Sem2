#include <stdio.h>
#include <stdlib.h>

int checkSparse(int **arr, int rows, int cols); 

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
    

    if (checkSparse(arr,rows,cols)==1)
     printf("\nGiven matrix is a sparse matrix");
    else
     printf("\nGiven matrix is not a sparse matrix");
     
    
    for(i=0;i<rows;++i)
     free(arr[i]);
    free(arr);   


    printf("\n----------------------------------------------------------\n");
    return 0;
 }


int checkSparse(int **arr, int rows, int cols)
 {
    int i=0, j=0;
    int count=0;
    int flag=0;
    int sparse_threshold = rows*cols/2;
    for (i = 0; i < rows; i++) 
     {
       for (j = 0; j < cols; j++) 
         {
           if(arr[i][j]==0)
            {
                ++count;
            }
            if(count>sparse_threshold)
             {
                flag=1;
                break;
             }
         }

         if(flag==1)
          break;
     }

    if(flag==1)
      return 1;
    else 
     return 0;

 }


