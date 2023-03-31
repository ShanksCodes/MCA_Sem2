#include <stdio.h>
#include <stdlib.h>

int checkIdentity(int **arr, int rows, int cols); 

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
    

    if(checkIdentity(arr,rows,cols)==1)
        printf("\nGiven Matrix is an identity matrix");
    else if(checkIdentity(arr,rows,cols)==-1)
        printf("\nSquare matrix can not be identity matrix!"); 
    else
        printf("\nGiven matrix is not an identity matrix!"); 


    for(i=0;i<rows;++i)
     free(arr[i]);
    free(arr);   


    printf("\n----------------------------------------------------------\n");
    return 0;
 }


int checkIdentity(int **arr, int rows, int cols)
 {
    int i=0, j=0;

    if (rows!=cols)  
        return -1;
   

    for (i = 0; i < rows; i++) 
     {
        for (j = 0; j < cols; j++) 
         {
            if((i==j && arr[i][j]!=1) || (i!=j && arr[i][j]!=0))
             {
                return 0;
             }
         }
     }

     return 1;
 }


