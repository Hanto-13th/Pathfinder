#include <stdio.h>  
#include <stdlib.h>
#include <math.h>

#include "node.h"
#include "djikstra.h"
#include "stack.h"
#include "visualization.h"

int main() {

    //init const var for matrice and algo
    const int matrice_size = 64;
    const int matrice_limit = sqrt(matrice_size);

    //init the matrice and the start/target node
    node_t **matrice_of_nodes = malloc(matrice_size * sizeof(node_t *)); 
    node_t *start_node = NULL; 
    node_t *end_node = NULL;

    //Init all nodes and add in the matrice
    node_creation_in_matrice(matrice_size,matrice_of_nodes);

    //Get all neighbor node for each node and assign it
    neighbor_node_assignment(matrice_size,matrice_limit, matrice_of_nodes);

    //the user choose the start node and the target node
    //and display the size of the matrice
    start_node = user_choose_start_node(matrice_of_nodes);
    end_node = user_choose_end_node(matrice_of_nodes);
    printf("MATRICE SIZE: %d x %d\n\n",matrice_limit,matrice_limit);

    //display the original matrice, compute the algo and display the results
    visu_base_matrice(matrice_size,matrice_limit);
    djikstra_algo(matrice_size,start_node,end_node);
    visu_djikstra(matrice_size,matrice_limit,matrice_of_nodes,start_node,end_node);

    //If the path between A and B is impossible
    if (end_node->value == INFINITY) {
    printf("NO PATH FOUND\n");
    }

    
    return 0; 
}
