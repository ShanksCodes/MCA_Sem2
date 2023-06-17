#include <stdio.h>
#include <stdlib.h>

void foo(int**arr);


int main()
{
  printf("\n----------------------------------------------------------\n");

    int **arr = (int **) calloc(10, sizeof(int *));
    for (int i = 0; i < 10; i++) 
        arr[i] = (int *) calloc(10, sizeof(int));
 foo(arr);
for(int i=0;i<3;i++)
{
  for(int j=0;j<3;j++)
  {
    printf("%d ",arr[i][j]);
  }
}

  printf("\n----------------------------------------------------------\n");
  return 0;
}

void foo(int**arr)
{
  arr[0][2]=100;

  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      printf("%d ",arr[i][j]);
    }
  }

}


