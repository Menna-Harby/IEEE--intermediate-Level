#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infix_to_postfix(char* expression, char* output) {
    Stack stack;
    init(&stack);
    char *token = strtok(expression, " ");
    output[0] = '\0';

    while (token) {
        if (isdigit(token[0])) {
            strcat(output, token);
            strcat(output, " ");
        } else if (token[0] == '(') {
            push(&stack, token);
        } else if (token[0] == ')') {
            while (!is_empty(&stack) && peek(&stack)[0] != '(') {
                strcat(output, pop(&stack));
                strcat(output, " ");
            }
            pop(&stack);
        } else {
            while (!is_empty(&stack) && precedence(peek(&stack)[0]) >= precedence(token[0])) {
                strcat(output, pop(&stack));
                strcat(output, " ");
            }
            push(&stack, token);
        }
        token = strtok(NULL, " ");
    }

    while (!is_empty(&stack)) {
        strcat(output, pop(&stack));
        strcat(output, " ");
    }
}

int evaluate_postfix(char* expression) {
    Stack stack;
    init(&stack);
    char *token = strtok(expression, " ");

    while (token) {
        if (isdigit(token[0])) {
            push(&stack, token);
        } else {
            int right = atoi(pop(&stack));
            int left = atoi(pop(&stack));
            char result[MAX];

            switch (token[0]) {
                case '+': sprintf(result, "%d", left + right); break;
                case '-': sprintf(result, "%d", left - right); break;
                case '*': sprintf(result, "%d", left * right); break;
                case '/': sprintf(result, "%d", left / right); break;
            }
            push(&stack, result);
        }
        token = strtok(NULL, " ");
    }
    return atoi(pop(&stack));
}

int main() {
    char infix_expr[MAX] = "3 + 5 * ( 2 - 8 )";
    char postfix_expr[MAX];
    infix_to_postfix(infix_expr, postfix_expr);
    printf("Infix Expression: %s\n", infix_expr);
    printf("Postfix Expression: %s\n", postfix_expr);
    printf("Evaluated Result: %d\n", evaluate_postfix(postfix_expr));
    return 0;
}
