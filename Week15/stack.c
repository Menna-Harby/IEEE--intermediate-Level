#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void init(Stack *s) {
    s->top = -1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char *item) {
    if (s->top < MAX - 1) {
        strcpy(s->items[++(s->top)], item);
    }
}

char* pop(Stack *s) {
    if (!is_empty(s)) {
        return s->items[(s->top)--];
    }
    return ""; // Return empty, if stack empty
}

char* peek(Stack *s) {
    if (!is_empty(s)) {
        return s->items[s->top];
    }
    return ""; 
}