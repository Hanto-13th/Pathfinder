#include <stdio.h>  
#include <stdlib.h>
#include <math.h>
#include "main.h"
#include "func.c"


int main() {

    int matrice_size = 64;
    int matrice_limit = matrice_size / sqrt(matrice_size);

    node_t *matrice_of_nodes[64]; //init the matrice 
    vector_of_mov_t mov_vector; //init the enum to list all vector of movement

    //Init all nodes and add in the matrice
    node_creation_in_matrice(matrice_size,matrice_of_nodes);

    //Get all neighbor node for each node and assign it
    neighbor_node_assignment(matrice_size,matrice_limit,matrice_of_nodes);

    
    return 0; 
}
