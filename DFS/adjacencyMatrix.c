#include <stdio.h>
#include <stdlib.h>

int checkIdentical(int **arr, int **arr2, int rows, int cols, int rows2, int cols2);
void createMatrix(int ***arr, int V);
void connectMatrix(int **arr, int V, int flag);
void printGraph(int **arr, int V);

int main()
{
    printf("----------------------------------------------------------\n\n");

    int V;
    int **arr;
    int flag = 0;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    createMatrix(&arr, V);

    printf("\nPress 0 if the graph is undirected, any other number for directed: ");
    scanf("%d", &flag);

    connectMatrix(arr, V, flag);
    printGraph(arr, V); 

    printf("\n----------------------------------------------------------\n");
    return 0;
}

void createMatrix(int ***arr, int V)
{
    *arr = (int **)calloc(V, sizeof(int *));
    int i = 0;
    for (i = 0; i < V; i++)
        (*arr)[i] = (int *)calloc(V, sizeof(int));
}

void connectMatrix(int **arr, int V, int flag)
{
    int i = 0, j = 0;
    int choice = 0;

    while (1)
    {
        printf("\nEnter vertices i and j to connect an edge from the ith to the jth vertex: ");
        scanf("%d%d", &i, &j);
        arr[i][j] = 1;
        if (!flag)
            arr[j][i] = 1;

        printf("\nPress -1 to exit, any other key to continue: ");
        scanf("%d", &choice);
        if (choice == -1)
            break;
    }
}

void printGraph(int **arr, int V)
{
    int i = 0, j = 0;
    printf("\nAdjacency Matrix:\n\n");

    for (i = 0; i < V; ++i)
    {
        for (j = 0; j < V; ++j)
        {
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\nLogs:\n");
    for (i = 0; i < V; ++i)
    {
        for (j = 0; j < V; ++j)
        {
            

            if (arr[i][j] == 1)
                printf("Vertex %d is connected to vertex %d\n", i, j);
        }
       
    }
}
