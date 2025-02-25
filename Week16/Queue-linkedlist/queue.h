#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct list
{
    char *data;
    struct list *next;
} list_t;

typedef struct queue
{
    list_t *first;
    list_t *last;
    size_t length; 
} queue;

list_t *create_new_node(char *data);
void init_queue(queue *queue);
bool enqueue(queue *q, char *data);
char *dequeue(queue *q);
char *peek(queue *q);

#endif 