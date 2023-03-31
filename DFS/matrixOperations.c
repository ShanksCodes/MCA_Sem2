#include <stdio.h>
#include <stdlib.h>

void printArray(int **result, int row, int col);
int addArrays(int **arr1, int **arr2, int **result, int row1, int col1, int row2, int col2); 
int subtractArrays(int **arr1, int **arr2, int **result, int row1, int col1m,int row2, int col2);
int multiplyArrays(int **arr1, int **arr2, int **result, int row1, int col1, int row2, int col2); 


int main() 
 {
    int row1=0, col1=0,row2=0,col2=0,i=0, j=0;
    int choice=0;

    printf("\n----------------------------------------------------------\n");
    printf("Enter the number of rows and columns for the 1st array: ");
    scanf("%d%d", &row1, &col1);

    printf("Enter the number of rows and columns for the 2nd array: ");
    scanf("%d%d", &row2, &col2);

    int **arr1 = (int **) malloc(row1 * sizeof(int *));
    int **arr2 = (int **) malloc(row2 * sizeof(int *));
    int **result = (int **) malloc(row1 * sizeof(int *));

    for (i = 0; i < row1; i++) 
     {
        arr1[i] = (int *) malloc(col1 * sizeof(int));
 
     }

     for (i = 0; i < row2; i++) 
      {
        arr2[i] = (int *) malloc(col2 * sizeof(int));
        result[i] = (int *) malloc(col2 * sizeof(int));  //even in addition it will stay valid cuz col2=col1
      }

    printf("\nEnter the elements of the first array:\n");
    for (i = 0; i < row1; i++) 
     {
        for (j = 0; j < col1; j++) {
            scanf("%d", &arr1[i][j]);
        }
     }

    printf("\nEnter the elements of the second array:\n");
    for (i = 0; i < row2; i++) 
     {
        for (j = 0; j < col2; j++) {
            scanf("%d", &arr2[i][j]);
        }
     }

    
    printf("\n1. Press 1 for addition of matrices");
    printf("\n2. Press 2 for subraction of matrices");
    printf("\n3. Press 3 for multiplication of matrices\n");
    scanf("%d", &choice);

    switch (choice) 
     {
        case 1:
               if(addArrays(arr1, arr2, result, row1, col1, row2, col2)==0)
                {
                  printf("\nThe sum of the two arrays is:\n");
                  printArray(result,row1,col2);
                }
               break;
            
        case 2:
                 if(subtractArrays(arr1, arr2, result, row1, col1, row2, col2)==0)
                  {
                   printf("The difference of the two arrays is:\n");
                   printArray(result,row1,col2);
                  }
                  break;

        case 3:
                 if(multiplyArrays(arr1, arr2, result, row1, col1, row2, col2)==0)
                  {
                   printf("The product of the two arrays is:\n");
                   printArray(result,row1,col2);
                  }
                  break;
      
        default:
            printf("Invalid entry:\n");

     }


   for(i=0;i<row1;++i)
     free(arr1[i]);
    free(arr1);   

   for(i=0;i<row2;++i)
     free(arr2[i]);
    free(arr2);   

   for(i=0;i<row1;++i)
     free(result[i]);
    free(result);   


    printf("\n----------------------------------------------------------\n");
    return 0;
 }


void printArray(int**result, int row, int col)
 {
   int i=0,j=0;

   for(i=0;i<row;++i)
    {
        for(j=0;j<col;++j)
         {
             printf("%d ",result[i][j]);
         }
        printf("\n"); 
    }

 }

int addArrays(int **arr1, int **arr2, int **result, int row1, int col1, int row2, int col2) 
 {
    int i=0, j=0;

    if (row1 != row2 || col1!=col2) 
     {
        printf("\nError: Addition must only be performed on square matrix.\n");
        return -1;
     }

    for (i = 0; i < row1; i++) 
     {
        for (j = 0; j < col1; j++) 
         {
            result[i][j] = arr1[i][j] + arr2[i][j];
         }
     }

     return 0;
 }


int subtractArrays(int **arr1, int **arr2, int **result, int row1, int col1, int row2, int col2)
 {
    int i, j;

    if (row1 != row2 || col1!=col2) 
     {
        printf("\nError: Subtraction must only be performed on square matrix.\n");
        return -1;
     }

    for (i = 0; i < row1; i++) 
     {
        for (j = 0; j < col1; j++) 
         {
            result[i][j] = arr1[i][j] - arr2[i][j];
         }
     }
     return 0;
 } 

int multiplyArrays(int **arr1, int **arr2, int **result, int row1, int col1, int row2, int col2) 
 {
    int i, j, k;
    if (col1 != row2) 
     {
        printf("Error: multiplication not possible. Number of columns in first array must be equal to the number of row1 in second array.\n");
        return -1;
     }

    for (i = 0; i < row1; i++)
      {
        for (j = 0; j < col2; j++)
          {
            result[i][j] = 0;
            for (k = 0; k < col1; k++) 
             {
                result[i][j] += arr1[i][k] * arr2[k][j];
             }
         }
     }
     return 0;
}
