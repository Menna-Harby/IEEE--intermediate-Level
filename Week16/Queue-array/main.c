#include "queue.h"

void display(QueueElement e) {
    printf("%d ", e);
}

int main() {
    Queue q;
    int initialCapacity = 3; 
    CreateQueue(&q, initialCapacity);

    Append(4, &q);
    Append(3, &q);
    Append(7, &q);
    Append(2, &q); 
    Append(9, &q);

    printf("Queue after appending elements: ");
    TraverseQueue(&q, display);

    printf("Served element: %d\n", serve(&q));

    Append(8, &q);

    printf("Queue after serving and appending: ");
    TraverseQueue(&q, display);

    ClearQueue(&q);
    printf("Queue after clearing: ");
    TraverseQueue(&q, display);

    FreeQueue(&q);

    return 0;
}