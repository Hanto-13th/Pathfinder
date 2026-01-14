#pragma once
#include "main.h"

//functions prototype for node creation
void node_creation_in_matrice(int matrice_size,node_t *matrice_of_nodes[]);
void neighbor_node_assignment(int matrice_size,int matrice_limit,node_t *matrice_of_nodes[]);

//functions prototype for algo Djikstra
int weight_between_two_nodes(node_t *node1, node_t *node2);
int sum_initial_to_actual_node();