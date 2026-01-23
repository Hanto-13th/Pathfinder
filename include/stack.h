#pragma once

typedef struct Node node_t;
typedef struct Stack stack_t;

//a struct to create a stack to handle all the nodes with the non minimum values finded
struct Stack {
    node_t **data;
    size_t size;
    size_t capacity;
};

//functions prototype for stack handling (the non tested nodes array)
stack_t *stack_new(size_t capacity);
void stack_push(stack_t *stack, node_t *node);
node_t *stack_pop(stack_t *stack);
void stack_free(stack_t *stack);
void sorting_the_min_value(stack_t *stack);