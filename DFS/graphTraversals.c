#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from source to destination
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // For undirected graph, add edge from destination to source as well
 /*    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;*/
}

void DFS(struct Graph* graph, int vertex) {
    struct Node* adjList = graph->adjLists[vertex];
    struct Node* temp = adjList;

    graph->visited[vertex] = 1;
    printf("Visited vertex: %d\n", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

void BFS(struct Graph* graph, int startVertex) {
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    graph->visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front != rear) {
        int currentVertex = queue[++front];
        printf("Visited vertex: %d\n", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];

        while (temp != NULL) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                queue[++rear] = adjVertex;
                graph->visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    printf("----------------------------------------------------------\n\n");

    int vertices, edges, i;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source vertex, destination vertex):\n");
    for (i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d%d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("\nAdjacency List Representation:\n");
    for (i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        printf("Adjacency list of vertex %d\n", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    printf("\nDFS Traversal:\n");
    for (i = 0; i < graph->numVertices; i++) {
        if (graph->visited[i] == 0) {
            DFS(graph, i);
        }
    }

    for (i = 0; i < vertices; i++) {
        graph->visited[i] = 0;
    }

    printf("\nBFS Traversal:\n");
    for (i = 0; i < graph->numVertices; i++) {
        if (graph->visited[i] == 0) {
            BFS(graph, i);
        }
    }

    printf("\n----------------------------------------------------------\n\n");

    return 0;
}
