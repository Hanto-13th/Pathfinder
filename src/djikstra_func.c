#include <stdio.h>  
#include <stdlib.h>
#include <stdbool.h>

#include "node.h"
#include "stack.h"
#include "djikstra.h"

//function to compute the weight between two nodes 
//(regular cost >> next neighbor = 1, diag neighbor = 2)
int weight_between_two_nodes(node_t *node1, node_t *node2) {
    size_t array_size = sizeof(node1->next_nodes)/sizeof(node1->next_nodes[0]);
    //for each iteration, verify if the node2 adress is in the node1 array and
    //if the index corresponding with next or diag neighbor
    //if not, return 0
    for(size_t i = 0;i < array_size;i++) {
        //if next neighbor
        if(i < 4 && node2 == node1->next_nodes[i]) {
            return 1;
        }
        //if diag neighbor
        else if(i >= 4 && node2 == node1->next_nodes[i]) {
            return 2;
        }
    }

    return -1;
    
}

//this function, compute the cost for all the neighbor of the actual node
//and keep only the cost if he's less at the previous value
//after if the neighbor is not already in the non tested array and locked
//we push him 
void neighbors_node_computing_cost(node_t *actual_node,stack_t *non_tested_nodes) {
    size_t array_lght = sizeof(actual_node->next_nodes) / sizeof(actual_node->next_nodes[0]);
    node_t *node_neighbor;
    int actual_node_value = actual_node->value;
    //for each neighbor, verify if the cost is less than actual and update 
    for(size_t i = 0; i < array_lght; i++) {
        node_neighbor = actual_node->next_nodes[i];
        if(node_neighbor == NULL) {
            continue;
        }
        int weight = weight_between_two_nodes(actual_node,node_neighbor);
        if(weight < 0) {
            continue;
        }
        if(node_neighbor->value > actual_node_value + weight) {

            node_neighbor->value = actual_node_value + weight;
        }
        //after cost computing, if the node is not already into the non tested array and is not locked
        //we push him into the array
        if(node_neighbor->locked == false && node_neighbor->in_queue == false) {
            stack_push(non_tested_nodes,node_neighbor);
        }

    }

}


void djikstra_algo(int matrice_size,node_t *initial_node,node_t *target_node) {
    //alloc an array to contain all the non tested nodes
    //non tested nodes = node where his cost is not the optimal
    //when the optimal cost is finded, the node is locked
    stack_t *non_tested_nodes = stack_new(matrice_size);

    //set a ptr actual node to follow the algo progress
    node_t *actual_node;

    //set the initial value at 0
    initial_node->value = 0;
    //push the start node in the non tested array
    stack_push(non_tested_nodes,initial_node);

    //while the target node is not locked (the optimal cost is not finded)
    while (target_node->locked == false)
    {
        //each iteration, we take the min value to lock him and find his neighbors
        node_t *node_with_min_value = stack_pop(non_tested_nodes);
        if(node_with_min_value == NULL) {
            return;
        }
        node_with_min_value->locked = true;
        actual_node = node_with_min_value;
        neighbors_node_computing_cost(actual_node,non_tested_nodes);


    }
    stack_free(non_tested_nodes);

}


