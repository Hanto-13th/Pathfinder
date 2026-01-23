#include <stdio.h>  
#include <stdlib.h>
#include <math.h>

#include "node.h"
#include "djikstra.h"
#include "stack.h"

int main() {

    int matrice_size = 64;
    int matrice_limit = matrice_size / sqrt(matrice_size);

    node_t *matrice_of_nodes[64]; //init the matrice 

    //Init all nodes and add in the matrice
    node_creation_in_matrice(matrice_size,matrice_of_nodes);

    //Get all neighbor node for each node and assign it
    neighbor_node_assignment(matrice_size,matrice_limit,matrice_of_nodes);

    
    return 0; 
}
