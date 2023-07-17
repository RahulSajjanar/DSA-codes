#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100

typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

typedef struct {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

void enqueue(Queue* q, int value) {
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    int item = q->items[q->front];
    q->front++;
    return item;
}

int isEmpty(Queue* q) {
    return q->rear < q->front;
}

void initializeGraph(Graph* graph, int numVertices) {
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* graph, int source, int destination) {
    graph->adjacencyMatrix[source][destination] = 1;
    graph->adjacencyMatrix[destination][source] = 1;
}

void bfsTraversal(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    Queue queue;
    queue.front = 0;
    queue.rear = -1;


    enqueue(&queue, startVertex);
    visited[startVertex] = 1;

    while (!isEmpty(&queue)) {
        int currentVertex = dequeue(&queue);
        printf("%d ", currentVertex);

        for (int i = 0; i <= graph->numVertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                enqueue(&queue, i);
                visited[i] = 1;
                visited[currentVertex] = 1;

            }
        }
    }
}

void generateRandomGraphFile(char* fileName, int numVertices, int numEdges) {
    FILE* file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error creating file.\n");
        return;
    }

    fprintf(file, "%d\n", numVertices);
    fprintf(file, "%d\n", numEdges);

    srand(time(NULL));

    for (int i = 0; i < numEdges; i++) {
        int source = rand() % numVertices;
        int destination = rand() % numVertices;
        fprintf(file, "%d %d\n", source, destination);
    }

    fclose(file);
}

int main() {
    Graph graph;
    int numVertices, numEdges, sourceVertex;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    char fileName[100];
    printf("Enter the file name to generate the random graph: ");
    scanf("%s", fileName);

    generateRandomGraphFile(fileName, numVertices, numEdges);

    printf("Enter the starting vertex for BFS traversal: ");
    scanf("%d", &sourceVertex);

    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(file, "%d", &numVertices);
    fscanf(file, "%d", &numEdges);

    initializeGraph(&graph, numVertices);

    for (int i = 0; i < numEdges; i++) {
        int source, destination;
        fscanf(file, "%d %d", &source, &destination);
        addEdge(&graph, source, destination);
    }

    fclose(file);

    printf("BFS Traversal: ");
    bfsTraversal(&graph, sourceVertex);

    return 0;
}
