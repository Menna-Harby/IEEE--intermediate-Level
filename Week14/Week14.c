#include <stdio.h>
#include <stdlib.h>


typedef struct Stack {
    int top;
    int arr[100];
} Stack;

// Create stack
void initStack(Stack* s) {
    s->top = -1;
}

// stack is empty?
int isEmpty(Stack* s) {
    return s->top == -1;
}

// stack is full?
int isFull(Stack* s) {
    return s->top == 100 - 1;
}

// stack size
int stackSize(Stack* s) {
    return s->top + 1;
}

// Push new entry onto the stack
void push(Stack* s, int data) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = data;
}

// Pop the entry off the top 
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

// Retreve the top entry off the stack
int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->top];
}

// Traverse the stack, visitng each entry
void traverse(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

// clear
void clearStack(Stack* s) {
    s->top = -1;
    printf("Stack cleared.\n");
}

int main() {
    Stack s;
    initStack(&s);
	
	
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    traverse(&s);
    
    printf("Stack size: %d\n", stackSize(&s));
    printf("Top element: %d\n", peek(&s));

    printf("Popped: %d\n", pop(&s));
    traverse(&s);

    clearStack(&s);
    traverse(&s);

}
