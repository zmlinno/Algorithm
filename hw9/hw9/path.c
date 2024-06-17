#include <stdio.h>
#include "backend.h"
#include <string.h>
#include <stdlib.h>

/****************************************
Implement Breadth-First Search on the graph constructed in "backend.c" and
use it in the find_path() below.

You can access functions and data structures constructed in "backend.c" via
"backend.h"
*****************************************/

// Node for queue
typedef struct QueueNode {
    int index;
    struct QueueNode* next;
} QueueNode;

// Queue structure
typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

// Function to check if the queue is empty
int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

// Function to enqueue an element
void enqueue(Queue* q, int index) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->index = index;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// Function to dequeue an element
int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        return -1;
    }
    QueueNode* temp = q->front;
    int index = temp->index;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return index;
}


void find_path(char start[5], char goal[5]) {
    int startIndex = search_index(start);
    int goalIndex = search_index(goal);

    if (startIndex == -1) {
        printf("Sorry. ");
        print_five_chars(start);
        printf(" is not in the dictionary.\n");
        return;
    }

    if (goalIndex == -1) {
        printf("Sorry. ");
        print_five_chars(goal);
        printf(" is not in the dictionary.\n");
        return;
    }

    if (startIndex == goalIndex) {
        printf("The start word is the same as the goal word.\n");
        return;
    }

    // BFS initialization
    int visited[N] = {0};
    int predecessor[N];
    for (int i = 0; i < N; i++) {
        predecessor[i] = -1;
    }

    Queue queue;
    initQueue(&queue);
    enqueue(&queue, startIndex);
    visited[startIndex] = 1;

    // BFS loop
    int found = 0;
    while (!isQueueEmpty(&queue)) {
        int current = dequeue(&queue);
        struct node* neighbor = adj_list[current];

        while (neighbor != NULL) {
            int neighborIndex = neighbor->index;

            if (!visited[neighborIndex]) {
                visited[neighborIndex] = 1;
                predecessor[neighborIndex] = current;
                enqueue(&queue, neighborIndex);

                if (neighborIndex == goalIndex) {
                    found = 1;
                    break;
                }
            }
            neighbor = neighbor->next;
        }
        if (found) {
            break;
        }
    }

    // Output the path if found
    if (found) {
        int path[N];
        int pathLength = 0;
        for (int at = goalIndex; at != -1; at = predecessor[at]) {
            path[pathLength++] = at;
        }
        printf("The shortest path from ");
        print_five_chars(start);
        printf(" to ");
        print_five_chars(goal);
        printf(" is:\n");
        for (int i = pathLength - 1; i >= 0; i--) {
            print_word(path[i]);
            if (i != 0) {
                printf(" -> ");
            }
        }
        printf("\n");
    } else {
        printf("No path found from ");
        print_five_chars(start);
        printf(" to ");
        print_five_chars(goal);
        printf(".\n");
    }
}
// void find_path(char start[5], char goal[5])
// {
//   int i,j,k,l;
  
//   i=search_index(start);
//   j=search_index(goal);

//   if (i<0) {
//     printf("Sorry. ");
//     print_five_chars(start);
//     printf(" is not in the dicitonary.");
//   }
//   else if (j<0) {
//     printf("Sorry. ");
//     print_five_chars(goal);
//     printf(" is not in the dicitonary.");
//   }
//   else {
//     printf("Hmm... I am trying to figure out the shortest path from ");
//     print_word(i); printf(" to "); print_word(j); printf(".\n");
//     for (l=0; l<150; l++) {
//       for (k=0; k<N; k++) {
// 	printf("Considering about ");
// 	print_word(k);
// 	printf("\r"); fflush(stdout);
//       }
//     }
//     printf("\nWell..., I don't know.  Please enlighten me ;)\n");
//   }
// }
  
