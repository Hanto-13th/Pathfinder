#include <stdio.h>  
#include <stdlib.h>
#include <stdbool.h>

#include "node.h"
#include "stack.h"

//func to create a new stack which contains all non tested nodes
stack_t *stack_new(size_t capacity) {
    if (capacity < 1) {
        return NULL;
    }

    stack_t *new_stack = malloc(sizeof(stack_t));
    //handle if allocation error
    if(new_stack == NULL) {
        return NULL;
    }
    //init the new stack at 0 and alloc memoory for data function of capacity
    //void * = size of pointer = 8 bytes
    new_stack->size = 0;
    new_stack->capacity = capacity;
    new_stack->data = malloc(capacity * sizeof(node_t *));
    //if alloc error
    if(new_stack->data == NULL) {
        free(new_stack);
        return NULL;
    }
    return new_stack;
    
    }

//function to push an object into the array (non tested nodes)
//args = the stack and the object to push
void stack_push(stack_t *stack, node_t *node) {
    //look if there are not enough space in the stack to add new obj  
    if(stack->size == stack->capacity) {
        //if not we double the capacity
        //and realloc the data to double the capacity too
        stack->capacity *= 2;
        node_t **new_data = realloc(stack->data,stack->capacity * sizeof(node_t *));
        //if realloc doesnt work
        if(new_data == NULL) {
        stack->capacity /= 2;
        return;
        }
        //the old data is remplaced
        stack->data = new_data;
    }
    //if there are enough space add the node in the continuity of array
    //and increment the size
    node->in_queue = true;
    stack->data[stack->size] = node;
    stack->size++;
    sorting_the_min_value(stack);
}

//func to delete the top element of the stack and return it
node_t *stack_pop(stack_t *stack) {
  if(stack->size == 0) {
    return NULL;
  }
  //decrement the size counter of the array and get the top element
  stack->size--;
  node_t *top = stack->data[stack->size];
  //clear pointer and return the top element
  stack->data[stack->size] = NULL; 
  top->in_queue = false;
  return top;
}

//func to free all the allocated memory from the stack
void stack_free(stack_t *stack) {
  if(stack == NULL) {
    return;
  }
  //free all the data into the stack
  if(stack->data != NULL) {
    free(stack->data);
  }
  //free the stack to finish
  free(stack);
}

//func to sort the node with the min value at the top of the array
//to find easier with the "stack_pop" function
void sorting_the_min_value(stack_t *stack) {
    if(stack == NULL || stack->size < 2) {
    return;
  }
  //find the node with min value throught the array
  node_t *last_node_in_array = stack->data[stack->size - 1];
  node_t *node_with_min_value = stack->data[0];
  size_t index_to_switch = 0;
  for(size_t i = 1;i < stack->size;i++) {
    if(stack->data[i]->value < node_with_min_value->value) {
        node_with_min_value = stack->data[i];
        index_to_switch = i;
    }
  }
  //switch the last element with the min value element
  stack->data[stack->size - 1] = node_with_min_value;
  stack->data[index_to_switch] = last_node_in_array;

}
