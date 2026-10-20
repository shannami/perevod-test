#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int value;
    struct StackNode* nextNode;
};

struct Stack {
    struct StackNode* head;
};

Stack* newStack()
{
    Stack* stack = malloc(sizeof(Stack));
    if (!stack)
        return NULL;
    stack->head = NULL;
    return stack;
}

int push(Stack* stack, int value)
{
    if (!stack) 
        return -1;

    struct StackNode* node = malloc(sizeof(struct StackNode));

    if (!node)
        return -1; 
        
    node->value = value;
    node->nextNode = stack->head;
    stack->head = node;

    return 0; 
}

int pop(Stack* stack)
{
    struct StackNode* oldNode = stack->head;
    int res = oldNode->value;

    stack->head = oldNode->nextNode;
    free(oldNode);

    return res;
}

int isEmpty(Stack* stack)
{
    return stack->head == NULL;
}

void deleteStack(Stack* stack)
{
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}
