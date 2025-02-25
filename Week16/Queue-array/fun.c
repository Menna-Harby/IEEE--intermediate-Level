#include "queue.h"

void CreateQueue(Queue *q, int capacity) {
    q->Front = 0;
    q->rear = -1;
    q->Size = 0;
    q->Capacity = capacity;
    q->Qu_Arr = (QueueElement *)malloc(capacity * sizeof(QueueElement));
    if (q->Qu_Arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

void Append(QueueElement e, Queue *q) {
    if (isQueueFull(q)) {
        q->Capacity *= 2;
        q->Qu_Arr = (QueueElement *)realloc(q->Qu_Arr, q->Capacity * sizeof(QueueElement));
        if (q->Qu_Arr == NULL) {
            printf("Memory reallocation failed!\n");
            exit(1);
        }
        printf("Queue resized to %d\n", q->Capacity);
    }
    q->rear = (q->rear + 1) % q->Capacity; 
    q->Qu_Arr[q->rear] = e;
    q->Size++;
}

QueueElement serve(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty! Cannot serve.\n");
        exit(1); 
    }
    QueueElement value = q->Qu_Arr[q->Front];
    q->Front = (q->Front + 1) % q->Capacity; 
    q->Size--;
    return value;
}

int isQueueEmpty(Queue *q) {
    return q->Size == 0;
}

int isQueueFull(Queue *q) {
    return q->Size == q->Capacity;
}

int QueueSize(Queue *q) {
    return q->Size;
}

void ClearQueue(Queue *q) {
    q->Front = 0;
    q->rear = -1;
    q->Size = 0;
}

void TraverseQueue(Queue *q, void (*f)(QueueElement)) {
    int pos, s;
    for (pos = q->Front, s = 0; s < q->Size; s++) {
        (*f)(q->Qu_Arr[pos]);
        pos = (pos + 1) % q->Capacity; 
    }
    printf("\n");
}

// Free dynamically allocated memory
void FreeQueue(Queue *q) {
    free(q->Qu_Arr);
    q->Qu_Arr = NULL;
    q->Front = 0;
    q->rear = -1;
    q->Size = 0;
    q->Capacity = 0;
}