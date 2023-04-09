#include <stdio.h>
#include <stdlib.h>

int findTotalValues(int **arr,int rows, int cols);
void rowTripletMatrix(int **arr,int**row_triplet_matrix, int rows, int cols,int total_values); 
void printArray(int**arr,int rows, int cols);
int main() 
 {
    int rows=0, cols=0,i=0,j=0;
    int total_values=0;
    
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

     total_values = findTotalValues(arr,rows,cols);


     int **row_triplet_matrix = (int **) calloc(3, sizeof(int *));
    
     for (i = 0; i < 3; i++) 
        row_triplet_matrix[i] = (int *) calloc((total_values+1), sizeof(int));
    
    rowTripletMatrix(arr,row_triplet_matrix,rows,cols,total_values);
    printf("\nCorrosponding row-triplet matrix for the given sparse matrix is:\n\n");
    printArray(row_triplet_matrix,3,total_values);



   for(i=0;i<rows;++i)
     free(arr[i]);
    free(arr);

   for(i=0;i<3;++i)
     free(row_triplet_matrix[i]);
    free(row_triplet_matrix);

    printf("\n----------------------------------------------------------\n");

    return 0;
 }


int findTotalValues(int**arr,int rows,int cols)
 {
   int i=0,j=0;
   int count=0;

   for(i=0;i<rows;++i)  
    {
        for(j=0;j<cols;++j)
          {
             if(arr[i][j]!=0)
             count++;
          }
    }
  
    return count;
 }

void rowTripletMatrix(int**arr, int**row_triplet_matrix, int rows, int cols, int total_values)
 {
    int i=0, j=0;
    int q=1;  //p will have values 0 1 and 2 while q from 1 to total_values
    row_triplet_matrix[0][0]=rows;
    row_triplet_matrix[1][0]=cols;
    row_triplet_matrix[2][0]=total_values;

    for(i=0;i<rows;++i)
     {
        for(j=0;j<cols;++j)
         {
            if(arr[i][j]!=0)
             {
                row_triplet_matrix[0][q]=i;
                row_triplet_matrix[1][q]=j;
                row_triplet_matrix[2][q]=arr[i][j];
                q++;
             }
          
         }
     }
    
 }

 void printArray(int**arr,int rows, int cols)
  {
    int i=0,j=0;
    for(i=0;i<rows;++i)
     {
        for(j=0;j<=cols;++j)
         {
            printf("%d ", arr[i][j]);
         }
         printf("\n");
     }
  }


