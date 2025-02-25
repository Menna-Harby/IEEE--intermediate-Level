#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef int QueueElement;

typedef struct Queue {
    int Front;          
    int rear;           
    int Size;           
    int Capacity;       
    QueueElement *Qu_Arr; 
} Queue;

// Function prototypes
void CreateQueue(Queue *q, int capacity);
void Append(QueueElement e, Queue *q);
QueueElement serve(Queue *q);
int isQueueEmpty(Queue *q);
int isQueueFull(Queue *q);
int QueueSize(Queue *q);
void ClearQueue(Queue *q);
void TraverseQueue(Queue *q, void (*f)(QueueElement));
void FreeQueue(Queue *q); 

#endif 