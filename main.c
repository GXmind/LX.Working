#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    char value;
    struct Node* next;
} Node;

typedef struct Graph {
    int numNodes;
    Node** adjList;
} Graph;

typedef struct Queue {
    int front, rear, size;
    unsigned capacity;
    char* array;
} Queue;

Node* createNode(char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int numNodes) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = numNodes;
    graph->adjList = (Node**)malloc(numNodes * sizeof(Node*));

    for (int i = 0; i < numNodes; ++i)
        graph->adjList[i] = NULL;

    return graph;
}

void addEdge(Graph* graph, char src, char dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src - 'A'];
    graph->adjList[src - 'A'] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest - 'A'];
    graph->adjList[dest - 'A'] = newNode;
}

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (char*)malloc(capacity * sizeof(char));
    return queue;
}

bool isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

bool isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, char item) {
    if (isFull(queue))
        return;

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

char dequeue(Queue* queue) {
    if (isEmpty(queue))
        return '\0';

    char item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int compareNodes(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

void bfs(Graph* graph, char start) {
    Queue* queue = createQueue(graph->numNodes);
    bool* visited = (bool*)malloc(graph->numNodes * sizeof(bool));

    for (int i = 0; i < graph->numNodes; ++i)
        visited[i] = false;

    enqueue(queue, start);
    visited[start - 'A'] = true;

    while (!isEmpty(queue)) {
        char current = dequeue(queue);
        printf("%c ", current);

        Node* temp = graph->adjList[current - 'A'];
        char* neighbors = (char*)malloc(graph->numNodes * sizeof(char));
        int count = 0;

        while (temp) {
            if (!visited[temp->value - 'A']) {
                neighbors[count++] = temp->value;
                visited[temp->value - 'A'] = true;
            }
            temp = temp->next;
        }

        qsort(neighbors, count, sizeof(char), compareNodes);

        for (int i = 0; i < count; ++i) {
            enqueue(queue, neighbors[i]);
        }

        free(neighbors);
    }

    free(queue);
    free(visited);
}

int main() {
    int numNodes, numEdges;
    scanf("%d %d", &numNodes, &numEdges);

    char* nodes = (char*)malloc(numNodes * sizeof(char));
    for (int i = 0; i < numNodes; ++i)
        scanf(" %c", &nodes[i]);

    Graph* graph = createGraph(numNodes);

    for (int i = 0; i < numEdges; ++i) {
        char src, dest;
        scanf(" %c %c", &src, &dest);
        addEdge(graph, src, dest);
    }
    bfs(graph, nodes[0]);
    printf(" \n");

    free(nodes);
    free(graph);

    return 0;
}



