#ifndef STACK_H
#define STACK_H

#define MAX 100

typedef struct Stack {
    int top;
    char items[MAX][MAX];
} Stack;

void init(Stack *s);
int is_empty(Stack *s);
void push(Stack *s, char *item);
char* pop(Stack *s);
char* peek(Stack *s);

#endif 