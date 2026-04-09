#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    struct node *next;
};
typedef struct node *GNODE;

GNODE graph[20];   

void print(int *N) {
    for (int i = 1; i <= *N; i++) {
        if (graph[i] != NULL) {
            printf("%d=>",i);
            GNODE temp = graph[i];
            while (temp != NULL) {
                printf("%d\t", temp->vertex);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

void insertVertex(int *N) {
    (*N)++;
    int newVertex = *N;
    int edgesFromExisting, edgesToExisting, src, dest;

    printf("Enter number of edges from existing vertices to new vertex : ");
    scanf("%d", &edgesFromExisting);
    for (int i = 0; i < edgesFromExisting; i++) {
        printf("Enter source vertex : ");
        scanf("%d", &src);
        if (src < 1 || src > *N - 1) {
            printf("Invalid vertex.\n");
            (*N)--;
            return;
        }
        GNODE newNode = (GNODE)malloc(sizeof(struct node));
        newNode->vertex = newVertex;
        newNode->next = NULL;
        if (graph[src] == NULL) {
            graph[src] = newNode;
        } else {
            GNODE p = graph[src];
            while (p->next != NULL) p = p->next;
            p->next = newNode;
        }
    }

    printf("Enter number of edges from new vertex to existing vertices : ");
    scanf("%d", &edgesToExisting);
    for (int i = 0; i < edgesToExisting; i++) {
        printf("Enter destination vertex : ");
        scanf("%d", &dest);
        if (dest < 1 || dest > *N - 1) {
            printf("Invalid vertex.\n");
            (*N)--; 
            return;
        }
        GNODE newNode = (GNODE)malloc(sizeof(struct node));
        newNode->vertex = dest;
        newNode->next = NULL;
        if (graph[newVertex] == NULL) {
            graph[newVertex] = newNode;
        } else {
            GNODE p = graph[newVertex];
            while (p->next != NULL) p = p->next;
            p->next = newNode;
        }
    }

    printf("After inserting vertex the adjacency list is : ");
    print(N);
}

void insertEdge(int *N) {
    int src, dest;
    printf("Enter the source vertex of the edge : ");
    scanf("%d", &src);
    printf("Enter the destination vertex of the edge : ");
    scanf("%d", &dest);

    if (src < 1 || src > *N || dest < 1 || dest > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    GNODE newNode = (GNODE)malloc(sizeof(struct node));
    newNode->vertex = dest;
    newNode->next = NULL;
    if (graph[src] == NULL) {
        graph[src] = newNode;
    } else {
        GNODE p = graph[src];
        while (p->next != NULL) p = p->next;
        p->next = newNode;
    }

    printf("After inserting edge the adjacency list is : \n");
    print(N);
}

void deleteVertex(int *N) {
    if (*N == 0) {
        printf("Graph is empty.\n");
        return;
    }

    int v;
    printf("Enter the vertex to be deleted : ");
    scanf("%d", &v);

    if (v < 1 || v > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    GNODE curr = graph[v];
    while (curr != NULL) {
        GNODE temp = curr;
        curr = curr->next;
        free(temp);
    }
    graph[v] = NULL;

    for (int i = 1; i <= *N; i++) {
        GNODE prev = NULL;
        curr = graph[i];
        while (curr != NULL) {
            if (curr->vertex == v) {
                if (prev == NULL)
                    graph[i] = curr->next;
                else
                    prev->next = curr->next;
                free(curr);
                break;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    printf("After deleting vertex the adjacency list is : \n");
    print(N);
}

void deleteEdge(int *N) {
    int src, dest;
    printf("Enter the source vertex of the edge : ");
    scanf("%d", &src);
    printf("Enter the destination vertex of the edge : ");
    scanf("%d", &dest);

    GNODE prev = NULL, curr = graph[src];
    while (curr != NULL) {
        if (curr->vertex == dest) {
            if (prev == NULL)
                graph[src] = curr->next;
            else
                prev->next = curr->next;
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("After deleting edge the adjacency list is : \n");
    print(N);
}

