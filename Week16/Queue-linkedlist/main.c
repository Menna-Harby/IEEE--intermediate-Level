#include "queue.h"

int main(void)
{
    queue q;
    init_queue(&q);

    printf("Test for enqueue\n\n");
    printf("Length: %lu\n", q.length);
    if (!enqueue(&q, "Google")) {
        fprintf(stderr, "Failed to enqueue 'Google'\n");
    }
    printf("Length: %lu\n", q.length);
    if (!enqueue(&q, "Udemy")) {
        fprintf(stderr, "Failed to enqueue 'Udemy'\n");
    }
    printf("Length: %lu\n", q.length);
    if (!enqueue(&q, "Discord")) {
        fprintf(stderr, "Failed to enqueue 'Discord'\n");
    }
    printf("Length: %lu\n", q.length);

    printf("\n\nTest for peek\n\n");
    char *peeked = peek(&q);
    if (peeked != NULL) {
        printf("Peeked: %s\n", peeked);
        free(peeked);  
    } else {
        printf("Queue is empty, nothing to peek.\n");
    }

    printf("\n\nTest for dequeue\n\n");
    while (q.length != 0)
    {
        char *data = dequeue(&q);
        if (data != NULL) {
            printf("Dequeued: %s\n", data);
            free(data);  
        } else {
            printf("Queue is empty, nothing to dequeue.\n");
        }
    }
    printf("Length: %lu\n", q.length);

    return 0;
}