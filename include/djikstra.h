#pragma once

typedef struct Node node_t;
typedef struct Stack stack_t;

//functions prototype for algo Djikstra
int weight_between_two_nodes(node_t *node1, node_t *node2);
void djikstra_algo(int matrice_size,node_t *initial_node,node_t *target_node);
void neighbors_node_computing_cost(node_t *actual_node,stack_t *non_tested_nodes);
