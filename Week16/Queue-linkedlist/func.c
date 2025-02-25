#include "queue.h"

char *my_strndup(const char *s, size_t n) {
    size_t len = strnlen(s, n); 
    char *copy = malloc(len + 1); 
    if (copy == NULL) {
        return NULL; 
    }
    memcpy(copy, s, len); 
    copy[len] = '\0';
    return copy; 
}

list_t *create_new_node(char *data)
{
    list_t *newnode = malloc(sizeof(list_t));
    if (newnode == NULL)
    {
        return NULL;
    }
    newnode->data = my_strndup(data, strlen(data)); 
    if (newnode->data == NULL) {
        free(newnode); 
        return NULL;
    }
    newnode->next = NULL;
    return newnode;
}

void init_queue(queue *queue)
{
    queue->first = NULL;
    queue->last = NULL;
    queue->length = 0;
}

bool enqueue(queue *q, char *data)
{
    if (q == NULL) return false;

    list_t *node = create_new_node(data);
    if (node == NULL) return false;

    if (q->last != NULL)
    {
        q->last->next = node;
    }
    q->last = node;

    if (q->first == NULL)
    {
        q->first = node;
    }

    q->length++;  
    return true;
}

char *dequeue(queue *q)
{
    if (q == NULL || q->first == NULL) return NULL;

    list_t *ptr = q->first;
    char *data = my_strndup(ptr->data, strlen(ptr->data)); 

    q->first = q->first->next;
    if (q->first == NULL) q->last = NULL;

    free(ptr->data);
    free(ptr);
    q->length--;  

    return data;
}

char *peek(queue *q)
{
    if (q == NULL || q->first == NULL) return NULL;

    return my_strndup(q->first->data, strlen(q->first->data)); 
}